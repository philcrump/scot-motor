#include "main.h"


static bool control_timer_initialised = false;
static virtual_timer_t control_timer_timer;
static systime_t control_timer_lastfeed = 0;

static bool control_timer_motor_enable = false;

static void control_timer_timeout(void *arg)
{
  (void)arg;

  control_timer_motor_enable = false;
  motor_set_stop();

  palClearLine(LINE_CONTROL_OK);
}

void control_timer_feed(void)
{
  palSetLine(LINE_CONTROL_OK);
  control_timer_motor_enable = true;

  if(!control_timer_initialised)
  {
    control_timer_initialised = true;
    chVTObjectInit(&control_timer_timer);
  }

  chVTSet(&control_timer_timer, TIME_MS2I(100), control_timer_timeout, NULL);
  control_timer_lastfeed = chVTGetSystemTime();
}

bool control_timer_get_motor_enable(void)
{
  return control_timer_motor_enable;
}

sysinterval_t control_timer_get_sysinterval_since_lastfeed(void)
{
  return chVTTimeElapsedSinceX(control_timer_lastfeed);
}