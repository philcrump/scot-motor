#ifndef __DIAGNOSTICS_H__
#define __DIAGNOSTICS_H__

bool brake_released(void);

void brake_set_released(void);

void brake_set_engaged(void);



THD_FUNCTION(diagnostics_service_thread, arg);

#endif /* __DIAGNOSTICS_H__ */