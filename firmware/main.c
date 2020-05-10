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

  if(vi_init())
  {
    sdWriteString(&SD2, "VI Init OK\r\n");
  }
  else
  {
    sdWriteString(&SD2, "VI Init FAILED\r\n");
  }

  motor_init();

  chThdCreateStatic(can_rx_service_wa, sizeof(can_rx_service_wa), NORMALPRIO, can_rx_service_thread, NULL);

  systime_t start, end;
  int32_t speed = 0;
  bool speed_direction = true;
  char speed_string[64];
  uint16_t voltage;
  int16_t current;
  while(true)
  {
    /* Set timer for 10s */
    start = chVTGetSystemTime();
    end = chTimeAddX(start, TIME_MS2I(10));

    can_send_sysinfo(GITVERSION_X32, system_mcutemperature());

    if(speed_direction)
    {
      if(speed > 1024)
      {
        speed_direction = false;
      }
      speed += 10;
    }
    else
    {
      if(speed < -1024)
      {
        speed_direction = true;
      }
      speed -= 10;
    }
    motor_set_speed(speed);

    chsnprintf(speed_string, 63, "Speed: %05d\r\n", speed);
    sdWriteString(&SD2, speed_string);

    if(vi_read_vi(&voltage, &current))
    {
      chsnprintf(speed_string, 63, "V: %dmV, I: %dmA\r\n", (uint16_t)((float)voltage * 1.25), (int16_t)((float)current * 1.25));
      sdWriteString(&SD2, speed_string);
    }
    else
    {
      sdWriteString(&SD2, "VI Read FAILED\r\n");
    }

    watchdog_feed(WATCHDOG_DOG_MAIN);
    while (chVTIsSystemTimeWithin(start, end))
    {
      /* Feed watchdog, sleep for 100ms, repeat */
      watchdog_feed(WATCHDOG_DOG_MAIN);
      chThdSleepMilliseconds(2);
    }
  }
}
