#include "main.h"


static void diagnostics_sysinfo(void)
{
  can_send_sysinfo(GITVERSION_X32, system_mcutemperature());
}

static uint16_t diagnostics_vi_voltage;
static int16_t diagnostics_vi_current;
static uint32_t diagnostics_control_interval;

static void diagnostics_motorinfo(void)
{
  vi_read_vi(&diagnostics_vi_voltage, &diagnostics_vi_current);

  diagnostics_control_interval = TIME_I2MS(control_timer_get_sysinterval_since_lastfeed());
  if(diagnostics_control_interval > 255)
  {
    diagnostics_control_interval = 255;
  }

  can_send_motorinfo(
    motor_get_speed_commanded(),
    diagnostics_vi_voltage,
    diagnostics_vi_current,
    (uint8_t)diagnostics_control_interval,
    signals_get_limit_1(),
    signals_get_limit_2(),
    signals_get_pwmfault(),
    control_timer_get_motor_enable()
  );
}

THD_FUNCTION(diagnostics_service_thread, arg)
{
  (void)arg;
  systime_t time;
  uint32_t counter;

  counter = 0;
  time = chVTGetSystemTimeX();
  while (1)
  {
    /* Set next deadline */
    time += TIME_MS2I(10);
    watchdog_feed(WATCHDOG_DOG_DIAGNOSTICS);

    diagnostics_motorinfo();
    if((counter & 0x000001FF) == 0x00000000)
    {
      diagnostics_sysinfo();
    }
    counter++;

    watchdog_feed(WATCHDOG_DOG_DIAGNOSTICS);
    chThdSleepUntil(time);
  }
}