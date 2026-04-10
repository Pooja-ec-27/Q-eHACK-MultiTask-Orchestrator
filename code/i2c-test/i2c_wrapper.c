/*
 * I2C WRAPPER LAYER
 * -------------------------
 * Abstracts low-level I2C operations
 * so application code remains clean.
 *
 * WHY THIS IS IMPORTANT:
 * → Hardware independence
 * → Easy debugging
 * → Reusable across sensors
 */

Functions
int i2c_read_byte(int bus, uint8_t addr, uint8_t reg, uint8_t *data);
int i2c_write_byte(int bus, uint8_t addr, uint8_t reg, uint8_t value);
