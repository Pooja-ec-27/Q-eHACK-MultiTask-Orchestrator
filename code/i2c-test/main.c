/*
 * ============================================================
 *  FILE: main.c
 *  ROLE: Application Layer
 *
 *  WHAT IT DOES:
 *  - Initializes BMP280 sensor
 *  - Continuously reads temperature & pressure
 *  - Prints output
 *
 *  WHY THIS FILE EXISTS:
 *  → Keeps high-level logic separate from hardware details
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "bmp280.h"
#include "i2c_wrapper.h"

#define I2C_BUS 1

int main(void)
{
    uint8_t chip_id = 0;

    puts("BMP280 I2C Test - Raspberry Pi");

    /* Step 1: Detect sensor */
    if (bmp280_detect(I2C_BUS, &chip_id) != 0) {
        puts("ERROR: BMP280 not detected");
        return EXIT_FAILURE;
    }

    printf("BMP280 detected! Chip ID = 0x%02X\n", chip_id);

    /* Step 2: Initialize sensor */
    bmp280_init(I2C_BUS);

    /* Step 3: Load calibration data */
    bmp280_read_calibration(I2C_BUS);

    /* Step 4: Continuous reading loop */
    while (1) {
        float temp = bmp280_get_temperature(I2C_BUS);
        float pres = bmp280_get_pressure(I2C_BUS);

        printf("Temperature : %.2f C\n", temp);
        printf("Pressure    : %.2f hPa\n", pres);
        puts("-----------------------------");

        delay(1000);
    }

    return EXIT_SUCCESS;
}
