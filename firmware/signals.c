#include "main.h"

static bool signals_initialised = false;

static const uint32_t signals_cb_arg_limit_1 = 1;
static const uint32_t signals_cb_arg_limit_2 = 2;
static const uint32_t signals_cb_arg_pwm_fault = 3;

static bool signals_limit_1 = false;
static bool signals_limit_2 = false;
static bool signals_pwmfault = false;

static void _signals_cb(void *arg)
{
  if(arg == &signals_cb_arg_limit_1)
  {
    signals_limit_1 = palReadLine(LINE_LIMIT_1);
  }
  else if(arg == &signals_cb_arg_limit_2)
  {
    signals_limit_2 = palReadLine(LINE_LIMIT_2);
  }
  else if(arg == &signals_cb_arg_pwm_fault)
  {
    signals_pwmfault = !palReadLine(LINE_PWM_nFAULT);
  }
}

void signals_init(void)
{
  if(signals_initialised)
  {
    return;
  }

  palEnableLineEvent(LINE_LIMIT_1, PAL_EVENT_MODE_BOTH_EDGES);
  palSetLineCallback(LINE_LIMIT_1, _signals_cb, (void *)&signals_cb_arg_limit_1);

  palEnableLineEvent(LINE_LIMIT_2, PAL_EVENT_MODE_BOTH_EDGES);
  palSetLineCallback(LINE_LIMIT_2, _signals_cb, (void *)&signals_cb_arg_limit_2);

  palEnableLineEvent(LINE_PWM_nFAULT, PAL_EVENT_MODE_BOTH_EDGES);
  palSetLineCallback(LINE_PWM_nFAULT, _signals_cb, (void *)&signals_cb_arg_pwm_fault);

  signals_limit_1 = palReadLine(LINE_LIMIT_1);
  signals_limit_2 = palReadLine(LINE_LIMIT_2);
  signals_pwmfault = !palReadLine(LINE_PWM_nFAULT);

  signals_initialised = true;
}

bool signals_get_limit_1(void)
{
  return signals_limit_1;
}

bool signals_get_limit_2(void)
{
  return signals_limit_2;
}

bool signals_get_pwmfault(void)
{
  return signals_pwmfault;
}