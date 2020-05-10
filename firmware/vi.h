#ifndef __VI_H__
#define __VI_H__

bool vi_init(void);

bool vi_read_vi(uint16_t *voltage, int16_t *current);

#endif /* __VI_H__ */