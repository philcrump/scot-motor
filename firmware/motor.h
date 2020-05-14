#ifndef __MOTOR_H__
#define __MOTOR_H__

void motor_init(void);

void motor_set_speed(int16_t speed);

void motor_set_stop(void);

int16_t motor_get_speed_commanded(void);

#endif /* __MOTOR_H__ */