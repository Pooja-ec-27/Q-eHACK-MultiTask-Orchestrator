#ifndef I2C_WRAPPER_H
#define I2C_WRAPPER_H

#include <stdint.h>

int i2c_read_byte(int bus, uint8_t addr, uint8_t reg, uint8_t *data);
int i2c_write_byte(int bus, uint8_t addr, uint8_t reg, uint8_t value);

void delay(int ms);

#endif
