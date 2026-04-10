#ifndef BMP280_H
#define BMP280_H

#include <stdint.h>

int bmp280_detect(int bus, uint8_t *chip_id);
void bmp280_init(int bus);
void bmp280_read_calibration(int bus);

float bmp280_get_temperature(int bus);
float bmp280_get_pressure(int bus);

#endif
