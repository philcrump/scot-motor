#include "main.h"

#include <string.h>

extern uint32_t config_can_address_prefix;

#define CAN_ADDRESS_SYSINFO   0x3
#define CAN_ADDRESS_MOTORINFO 0x4
#define CAN_ADDRESS_COMMAND   0xA
#define CAN_ADDRESS_MOTORPWM  0xB

/*
  CAN_MCR_ABOM - Automatic Bus-Off Management
  CAN_MCR_AWUM - Automatic Wake-Up Management
  CAN_MCR_TXFP - Transmit FIFO Priority Mode (set = chronological, cleared = indentifier)

  CAN_BTR_LBKM - Loopback Mode (RX only sees TX)
  CAN_BTR_SILM - Silent Mode (TX doesn't go on the wire)
  CAN_BTR_SJW - Set Re-synchonisation Jump Width
  CAN_BTR_TS1 / CAN_BTR_TS2 - Set Time Segments
  CAN_BTR_BRP - Set time quantum prescaler
   - PCLK (=SYSCLK=PLL=6*8MHz) = 48MHz, target baudrate = 1Mbps, therefore 48 clocks / bit
      tq = (_BRP+1) = 3 clocks
      Sync _SJW = 1 = 3 clocks
      Segment 1 (sync <-> sample) _TS1 = 11x3 = 33 clocks
      Segment 2 (sample <-> transmission) _TS2 = 2x3 = 6 clocks
      Found empirically to be 1us per bit = 1Mb/s
*/

static const CANConfig can_cfg = {
  .mcr = CAN_MCR_TXFP | CAN_MCR_ABOM,
  .btr = CAN_BTR_SJW(2) | CAN_BTR_TS2(2) | CAN_BTR_TS1(11) | CAN_BTR_BRP(2)
};

static CANFilter can_filter = {
  .filter = 1, // Number of filter bank to be programmed
  .mode = 0, // 0 = mask, 1 = list
  .scale = 0, // 0 = 16bits, 1 = 32bits
  .assignment = 0, // (must be set to 0)
  .register1 = 0x0, // identifier 1 (loaded from config at runtime)
  .register2 = 0x07F0 // mask if mask mode, identifier2 if list mode
};

void can_send_sysinfo(const uint32_t gitversion, const int8_t temperature_degrees)
{
    CANTxFrame txmsg;

    txmsg.IDE = CAN_IDE_STD; // Identifier Type: Standard
    txmsg.SID = config_can_address_prefix | CAN_ADDRESS_SYSINFO; // Standard Identifier Value (11bits)
    txmsg.RTR = CAN_RTR_DATA; // Frame Type
    txmsg.DLC = 8; // Data Length (max = 8)
    txmsg.data8[0] = (gitversion >> 24) & 0xFF;
    txmsg.data8[1] = (gitversion >> 16) & 0xFF;
    txmsg.data8[2] = (gitversion >> 8) & 0xFF;
    txmsg.data8[3] = gitversion & 0xFF;
    txmsg.data8[4] = temperature_degrees & 0xFF;
    txmsg.data8[5] = 0x00; // SPARE
    txmsg.data8[6] = (CAND1.can->ESR >> 24) & 0xFF; // Receive Error Counter
    txmsg.data8[7] = (CAND1.can->ESR >> 16) & 0xFF; // Transmit Error Counter

    canTransmitTimeout(&CAND1, CAN_ANY_MAILBOX, &txmsg, TIME_IMMEDIATE);
}

void can_send_motorinfo(
  const int16_t motor_commanded,
  const uint16_t voltage,
  const int16_t current,
  const uint8_t control_last_interval_ms,
  const bool limit_1,
  const bool limit_2,
  const bool motor_fault,
  const bool control_timer_enable)
{
    CANTxFrame txmsg;

    txmsg.IDE = CAN_IDE_STD; // Identifier Type: Standard
    txmsg.SID = config_can_address_prefix | CAN_ADDRESS_MOTORINFO; // Standard Identifier Value (11bits)
    txmsg.RTR = CAN_RTR_DATA; // Frame Type
    txmsg.DLC = 8; // Data Length (max = 8)
    txmsg.data16[0] = motor_commanded;
    //txmsg.data8[1]
    txmsg.data16[1] = voltage;
    //txmsg.data8[3]
    txmsg.data16[2] = current;
    //txmsg.data8[5]
    txmsg.data8[6] = control_last_interval_ms;
    txmsg.data8[7] = limit_1 << 7
                    | limit_2 << 6
                    | motor_fault << 5
                    | control_timer_enable << 4;

    canTransmitTimeout(&CAND1, CAN_ANY_MAILBOX, &txmsg, TIME_IMMEDIATE);
}

static const uint8_t can_command_reset[5] = { 'R', 'E', 'S', 'E', 'T'};
static void can_rx_process(CANRxFrame *message)
{
  if(message->RTR == CAN_RTR_DATA
    && message->IDE == CAN_IDE_STD)
  {
    if((message->SID & 0x7F0) == config_can_address_prefix)
    {
      /* Message is for us */
      if((message->SID & 0xF) == CAN_ADDRESS_COMMAND)
      {
        /* Command Message */
        if(0 == memcmp(can_command_reset, message->data8, sizeof(can_command_reset)))
        {
          /* Reset Command! */
          system_reset();
        }
      }
      else if((message->SID & 0xF) == CAN_ADDRESS_MOTORPWM)
      {
        /* Motor PWM Command */
        control_timer_feed();
        motor_set_speed(message->data16[0]);
      }
    }
  }
}

THD_FUNCTION(can_rx_service_thread, arg)
{
    (void)arg;

    msg_t result;
    CANRxFrame rxmsg;

    can_filter.register1 = config_can_address_prefix;
    canSTM32SetFilters(&CAND1, 1, 1, &can_filter);

    canStart(&CAND1, &can_cfg);

    while(1)
    {
        result = canReceiveTimeout(&CAND1, CAN_ANY_MAILBOX, &rxmsg, TIME_MS2I(100));
        if(result == MSG_OK)
        {
            /* Message Received */
            can_rx_process(&rxmsg);
        }

        watchdog_feed(WATCHDOG_DOG_CANRX);
    }
}