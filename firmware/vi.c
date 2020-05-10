#include "main.h"

#define VI_I2C_ADDR 0b1000000

/* Standard Mode, 100Kb/s, I2CCLK = PCLK = 48MHz, from Table 93, p651 of RM */
static const I2CConfig vi_i2ccfg = {
  STM32_TIMINGR_PRESC(0xB) |
  STM32_TIMINGR_SCLDEL(0x4) | STM32_TIMINGR_SDADEL(0x2) |
  STM32_TIMINGR_SCLH(0xF)   | STM32_TIMINGR_SCLL(0x13),
  0,
  0
};

static bool vi_initialised = false;

bool vi_init(void)
{
  if(vi_initialised)
  {
    return true;
  }
  i2cStart(&I2CD1, &vi_i2ccfg);

  /* Test: manufacturer ID (0xFE) == 0x5449 */
  msg_t status;
  uint8_t vi_i2c_buffer_tx[3];
  uint8_t vi_i2c_buffer_rx[2];
  vi_i2c_buffer_tx[0] = 0xFE;
  vi_i2c_buffer_rx[0] = 0x55;
  i2cAcquireBus(&I2CD1);
  status = i2cMasterTransmitTimeout(&I2CD1, VI_I2C_ADDR,
                          vi_i2c_buffer_tx, 1,
                          vi_i2c_buffer_rx, 2,
                          TIME_MS2I(10));
  i2cReleaseBus(&I2CD1);

  if(status != MSG_OK)
  {
    return false;
  }

  if(vi_i2c_buffer_rx[0] != 0x54
    ||vi_i2c_buffer_rx[1] != 0x49)
  {
    return false;
  }

  /* Configure: Sample Time: 1.1ms, Average: 4x, Current & Voltage Continuous */
  vi_i2c_buffer_tx[0] = 0x00;
  vi_i2c_buffer_tx[1] = 0x63;
  vi_i2c_buffer_tx[2] = 0x27;
  i2cAcquireBus(&I2CD1);
  status = i2cMasterTransmitTimeout(&I2CD1, VI_I2C_ADDR,
                          vi_i2c_buffer_tx, 3,
                          vi_i2c_buffer_rx, 0,
                          TIME_MS2I(10));
  i2cReleaseBus(&I2CD1);

  if(status != MSG_OK)
  {
    return false;
  }

  vi_initialised = true;
  return true;
}

/* This takes approximately 1ms at 100Kb/s */
bool vi_read_vi(uint16_t *voltage, int16_t *current)
{
  if(!vi_init())
  {
    return false;
  }

  msg_t status;
  uint8_t vi_i2c_tx;
  uint8_t vi_i2c_buffer_rx[2];

  vi_i2c_tx = 0x01;
  i2cAcquireBus(&I2CD1);
  status = i2cMasterTransmitTimeout(&I2CD1, VI_I2C_ADDR,
                          &vi_i2c_tx, 1,
                          vi_i2c_buffer_rx, 2,
                          TIME_MS2I(10));
  if(status != MSG_OK)
  {
    i2cReleaseBus(&I2CD1);
    return false;
  }

  *current = (vi_i2c_buffer_rx[0] << 8) | vi_i2c_buffer_rx[1];

  vi_i2c_tx = 0x02;
  status = i2cMasterTransmitTimeout(&I2CD1, VI_I2C_ADDR,
                          &vi_i2c_tx, 1,
                          vi_i2c_buffer_rx, 2,
                          TIME_MS2I(10));
  if(status != MSG_OK)
  {
    i2cReleaseBus(&I2CD1);
    return false;
  }

  *voltage = (vi_i2c_buffer_rx[0] << 8) | vi_i2c_buffer_rx[1];

  i2cReleaseBus(&I2CD1);

  return true;
}