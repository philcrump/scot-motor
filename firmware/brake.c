#include "main.h"

static bool brake_state_released = false;

bool brake_released(void)
{
  return brake_state_released;
}

void brake_set_released(void)
{
  if(!brake_state_released)
  {
    palClearLine(LINE_nBRAKE);
    brake_state_released = true;
  }
}

void brake_set_engaged(void)
{
  if(brake_state_released)
  {
    palSetLine(LINE_nBRAKE);
    brake_state_released = false;
  }
}