#include "main.h"

#include "chprintf.h"

static const SerialConfig serial_cfg = {
  115200,
  0,
  0,
  0
};

void sdWriteString(SerialDriver *sdp, const char *string)
{
  uint32_t i;
  for(i = 0; string[i] != '\0'; i++)
  {
    sdPut(sdp, string[i]);
  }
}

THD_WORKING_AREA(can_rx_service_wa, 128);
THD_WORKING_AREA(watchdog_service_wa, 128);

int main(void)
{
  halInit();
  chSysInit();

  watchdog_init();
  chThdCreateStatic(watchdog_service_wa, sizeof(watchdog_service_wa), HIGHPRIO, watchdog_service_thread, NULL);

  /* Start Debug Console */
  sdStart(&SD2, &serial_cfg);

  sdWriteString(&SD2, "SCOT Motor Interface - Phil Crump M0DNY\r\n");
  sdWriteString(&SD2, " - Version: " GITVERSION "\r\n");

  if(!vi_init())
  {
    sdWriteString(&SD2, "VI Init FAILED\r\n");
    system_reset();
  }

  motor_init();

  chThdCreateStatic(can_rx_service_wa, sizeof(can_rx_service_wa), NORMALPRIO, can_rx_service_thread, NULL);

  systime_t start, end;
  uint16_t vi_voltage;
  int16_t vi_current;
  uint32_t motor_control_interval;
  while(true)
  {
    /* Set timer for 10s */
    start = chVTGetSystemTime();
    end = chTimeAddX(start, TIME_MS2I(10));
    
    can_send_sysinfo(GITVERSION_X32, system_mcutemperature());

    vi_read_vi(&vi_voltage, &vi_current);
    motor_control_interval = TIME_I2MS(control_timer_get_sysinterval_since_lastfeed());
    if(motor_control_interval > 255)
    {
      motor_control_interval = 255;
    }

    can_send_motorinfo(
      motor_get_speed_commanded(),
      vi_voltage,
      vi_current,
      (uint8_t)motor_control_interval,
      false, //estop
      false, //limit_1
      false, //limit_2
      motor_get_nfault(),
      control_timer_get_motor_enable()
    );

    while (chVTIsSystemTimeWithin(start, end))
    {
      /* Feed watchdog, sleep for 50ms, repeat */
      chThdSleepMilliseconds(2);
    }
    watchdog_feed(WATCHDOG_DOG_MAIN);
  }
}
