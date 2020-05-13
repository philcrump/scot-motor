#ifndef __CONTROL_TIMER_H__
#define __CONTROL_TIMER_H__

void control_timer_feed(void);

bool control_timer_get_motor_enable(void);

sysinterval_t control_timer_get_sysinterval_since_lastfeed(void);

#endif /* __CONTROL_TIMER_H__ */