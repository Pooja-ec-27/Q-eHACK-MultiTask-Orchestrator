## Firmware
### Libraries Used :<br>
* Standard C Libraries<br>
* I2C Communication Library (rpi_i2c.h)<br>

### Source Code<br>
#### 1. I2C Functional Verification and Sensor Testing<br>
**1.The below code is used to check the functional verification and testing of the circuit components**
```cpp
#include <stdio.h>      // For printing output
#include <stdlib.h>     // For exiting functions
#include <unistd.h>     // For delay
#include <stdint.h>     // For fixed-size data types

#include "rpi_i2c.h"   // I2C communication library
// config.h files

#define BMP280_ADDR 0x76        // Sensor I2C address
#define BMP280_REG_ID 0xD0      // Chip ID register
#define BMP280_REG_RESET 0xE0   // Reset register
#define BMP280_REG_STATUS 0xF3  // Status register

#define BMP280_REG_CTRL_M 0xF4  // Control register
#define BMP280_REG_CONFIG 0xF5  // Configuration register

#define BMP280_REG_PRESS_MSB 0xF7   // Pressure MSB
#define BMP280_REG_PRESS_LSB 0xF8   // Pressure LSB
#define BMP280_REG_PRESS_XLSB 0xF9  // Pressure XLSB

#define BMP280_REG_TEMP_MSB 0xFA    // Temp MSB
#define BMP280_REG_TEMP_LSB 0xFB    // Temp LSB
#define BMP280_REG_TEMP_XLSB 0xFC   // Temp XLSB

#define BMP280_REG_CALIB 0x88       // Calibration start
#define I2C_BUS 1                  // I2C bus number

typedef struct {
    uint16_t dig_T1;   // Temp calibration
    int16_t dig_T2;
    int16_t dig_T3;

    uint16_t dig_P1;   // Pressure calibration
    int16_t dig_P2;
    int16_t dig_P3;
    int16_t dig_P4;
    int16_t dig_P5;
    int16_t dig_P6;
    int16_t dig_P7;
    int16_t dig_P8;
    int16_t dig_P9;
} bmp280_calib_t;

static bmp280_calib_t calib;   // Store calibration data
static int32_t t_fine;         // Intermediate variable
// api smbus_read()
static void read_register(uint8_t reg, uint8_t *data)
{
    smbus_read_byte_data(I2C_BUS, BMP280_ADDR, reg, data); // Read 1 byte from sensor
}

static void bmp280_read_calibration(void)
{
    uint8_t raw[24];   // Raw calibration bytes

    for (int i = 0; i < 24; i++)                     // Read 24 bytes
        read_register(BMP280_REG_CALIB + i, &raw[i]);

    calib.dig_T1 = (raw[1] << 8) | raw[0];           // Combine bytes
    calib.dig_T2 = (raw[3] << 8) | raw[2];
    calib.dig_T3 = (raw[5] << 8) | raw[4];

    calib.dig_P1 = (raw[7] << 8) | raw[6];
    calib.dig_P2 = (raw[9] << 8) | raw[8];
    calib.dig_P3 = (raw[11] << 8) | raw[10];
    calib.dig_P4 = (raw[13] << 8) | raw[12];
    calib.dig_P5 = (raw[15] << 8) | raw[14];
    calib.dig_P6 = (raw[17] << 8) | raw[16];
    calib.dig_P7 = (raw[19] << 8) | raw[18];
    calib.dig_P8 = (raw[21] << 8) | raw[20];
    calib.dig_P9 = (raw[23] << 8) | raw[22];
}

float get_temp_value(void)
{
    uint8_t msb, lsb, xlsb;

    read_register(BMP280_REG_TEMP_MSB, &msb);   // Read temp MSB
    read_register(BMP280_REG_TEMP_LSB, &lsb);   // Read temp LSB
    read_register(BMP280_REG_TEMP_XLSB, &xlsb); // Read temp XLSB

    int32_t adc_T = (msb << 12) | (lsb << 4) | (xlsb >> 4); // Combine data

    int32_t var1 = ((adc_T >> 3) - (calib.dig_T1 << 1)) * calib.dig_T2 >> 11; // Calc
    int32_t var2 = (((adc_T >> 4) - calib.dig_T1) * ((adc_T >> 4) - calib.dig_T1) >> 12) * calib.dig_T3 >> 14;

    t_fine = var1 + var2;   // Store intermediate

    return (t_fine * 5 + 128) / 25600.0; // Return temp in °C
}

float get_pressure_value(void)
{
    uint8_t msb, lsb, xlsb;

    read_register(BMP280_REG_PRESS_MSB, &msb);   // Read pressure MSB
    read_register(BMP280_REG_PRESS_LSB, &lsb);   // Read pressure LSB
    read_register(BMP280_REG_PRESS_XLSB, &xlsb); // Read pressure XLSB

    int32_t adc_P = (msb << 12) | (lsb << 4) | (xlsb >> 4); // Combine

    int64_t var1 = t_fine - 128000;   // Calculation

    if (var1 == 0) return 0;          // Avoid error

    int64_t p = 1048576 - adc_P;     
    p = (p * 3125) / var1;           // Compute pressure

    return p / 25600.0;              // Return in hPa
}

int main(void)
{
    uint8_t chip_id = 0;   // Store sensor ID
    uint8_t status = 0;    // Store status

    puts("BMP280 I2C Test - QNX RTOS"); // Print title

    if (smbus_read_byte_data(I2C_BUS, BMP280_ADDR, BMP280_REG_ID, &chip_id) != I2C_SUCCESS)
    {
        puts("ERROR: Sensor not detected"); // If fail
        return EXIT_FAILURE;
    }

    if (chip_id != 0x58 && chip_id != 0x60)
    {
        puts("ERROR: Wrong device ID"); // Wrong sensor
        return EXIT_FAILURE;
    }
```
--------------
