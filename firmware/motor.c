#include "main.h"

static PWMConfig pwmcfg = {
  1024*20000,                               /* 20kHz PWM clock frequency     */
  1024,                                     /* Initial PWM period 1 second   */
  NULL,                                     /* No period callback            */
  {
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},          /* CH1: Active High, no callback */
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},          /* CH2: Active High, no callback */
   {PWM_OUTPUT_DISABLED, NULL},             /* CH3: Disabled                 */
   {PWM_OUTPUT_DISABLED, NULL}              /* CH4: Disabled                 */
  },
  0,                                        /* Control Register 2.            */
  0                                         /* DMA/Interrupt Enable Register. */
};

static uint16_t motor_speed_commanded = 0;

void motor_init(void)
{
    pwmStart(&PWMD1, &pwmcfg);
    motor_set_stop();
}

static inline void motor_set_stop_ch0(void)
{
  if(pwmIsChannelEnabledI(&PWMD1, 0))
  {
    pwmDisableChannel(&PWMD1, 0);
  }
}

static inline void motor_set_stop_ch1(void)
{
  if(pwmIsChannelEnabledI(&PWMD1, 1))
  {
    pwmDisableChannel(&PWMD1, 1);
  }
}


void motor_set_stop(void)
{
  motor_set_stop_ch0();
  motor_set_stop_ch1();

  brake_set_engaged();

  motor_speed_commanded = 0;
}

void motor_set_speed(int16_t speed)
{
  if(!control_timer_get_motor_enable())
  {
    motor_set_stop();
    return;
  }

  if(speed == 0)
  {
    motor_set_stop();
  }
  else
  {
    brake_set_released();

    if(speed > 0)
    {
      motor_set_stop_ch1();
      if(speed > 1024)
      {
        speed = 1024;
      }
      pwmEnableChannel(&PWMD1, 0, (uint32_t)speed);
      motor_speed_commanded = speed;
    }
    else
    {
      motor_set_stop_ch0();
      if(speed < -1024)
      {
        speed = -1024;
      }
      pwmEnableChannel(&PWMD1, 1, (uint32_t)(-1*speed));
      motor_speed_commanded = speed;
    }
  } 
}

int16_t motor_get_speed_commanded(void)
{
  return motor_speed_commanded;
}