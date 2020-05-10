#ifndef __MOTOR_H__
#define __MOTOR_H__

void motor_init(void);

bool motor_get_nfault(void);

void motor_set_speed(int32_t speed);

void motor_set_stop(void);

#endif /* __MOTOR_H__ */