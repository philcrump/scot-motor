#include "main.h"
#include "chprintf.h"

extern char config_device_id_hexstr[25];
extern char config_can_address_prefix_hexstr[5];

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
THD_WORKING_AREA(diagnostics_service_wa, 128);

int main(void)
{
  halInit();
  chSysInit();

  watchdog_init();
  chThdCreateStatic(watchdog_service_wa, sizeof(watchdog_service_wa), HIGHPRIO, watchdog_service_thread, NULL);

  config_init();

  /* Start Debug Console */
  sdStart(&SD2, &serial_cfg);

  sdWriteString(&SD2, "SCOT Motor Interface - Phil Crump M0DNY\r\n");
  sdWriteString(&SD2, " - Version: " GITVERSION "\r\n");
  sdWriteString(&SD2, " - STM32 ID: ");
  sdWriteString(&SD2, config_device_id_hexstr);
  sdWriteString(&SD2, "\r\n");
  sdWriteString(&SD2, " - CAN ADDRESS: ");
  sdWriteString(&SD2, config_can_address_prefix_hexstr);
  sdWriteString(&SD2, "\r\n");

  if(!vi_init())
  {
    sdWriteString(&SD2, "VI Init FAILED\r\n");
    system_reset();
  }

  signals_init();
  motor_init();

  chThdCreateStatic(can_rx_service_wa, sizeof(can_rx_service_wa), NORMALPRIO, can_rx_service_thread, NULL);

  chThdCreateStatic(diagnostics_service_wa, sizeof(diagnostics_service_wa), NORMALPRIO, diagnostics_service_thread, NULL);

  while(true)
  {
    chThdSleepMilliseconds(100);
    watchdog_feed(WATCHDOG_DOG_MAIN);
  }
}
