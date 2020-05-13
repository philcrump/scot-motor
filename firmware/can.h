#ifndef __CAN_H__
#define __CAN_H__

void can_init(void);

void can_send_position_and_fault(const uint16_t position_value, const uint8_t fault_value);

void can_send_sysinfo(const uint32_t gitversion, const int8_t temperature_degrees);

void can_send_motorinfo(
  const int16_t motor_commanded,
  const uint16_t voltage,
  const int16_t current,
  const uint8_t control_last_interval_ms,
  const bool estop,
  const bool limit_1,
  const bool limit_2,
  const bool motor_fault,
  const bool control_timer_enable);

THD_FUNCTION(can_rx_service_thread, arg);

#endif /* __CAN_H__ */