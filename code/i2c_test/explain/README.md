## BMP280 I2C Connection Test – Code Explanation
### 1. Purpose of the Code<br>

This program is used to:<br>

* Check whether the BMP280 sensor is connected via I2C<br>
* Verify communication between Raspberry Pi and sensor<br>
* Read temperature and pressure values<br>

### 2. I2C Address<br>

**#define BMP280_ADDR 0x76**

* This is the I2C address of the BMP280 sensor<br>
* If SDO is connected to GND → address is 0x76<br>
* If SDO is connected to VCC → address becomes 0x77<br>

### 3. Important Register

**#define BMP280_REG_ID 0xD0**
* This register stores the chip ID<br>
* Used to confirm if the sensor is detected<br>

### 4. How I2C Connection is Checked
**smbus_read_byte_data(I2C_BUS, BMP280_ADDR, BMP280_REG_ID, &chip_id);**
* Raspberry Pi sends request to address 0x76<br>
* It asks for register 0xD0 (chip ID)<br>
* Sensor responds with its ID<br>
**Expected Output:**<br>
0x58 → BMP280 detected<br>
0x60 → BME280 detected<br>
**If failed:** <br>
Sensor not connected properly<br>
Wrong wiring or address<br>

### 5. Sensor Detection Logic
**if (chip_id != 0x58 && chip_id != 0x60)**
* If ID is not correct → error is printed<br>
* If correct → sensor is successfully detected<br>

### 6. Sensor Initialization
**smbus_write_byte_data(I2C_BUS, BMP280_ADDR, BMP280_REG_RESET, 0xB6);**
Resets the sensor<br>
Prepares it for fresh readings<br>

### 7. Reading Sensor Data<br>
**Temperature**
Reads raw data from registers<br>
Applies calibration<br>
Converts to °C<br>
**Pressure**
Reads raw pressure data<br>
Uses calibration values<br>
Converts to hPa<br>
### 8. Continuous Monitoring
* Runs in loop<br>
* Reads temperature and pressure every 1 second<br>

### 9. Output Example<br>

 <br> <img width="1600" height="850" alt="image" src="https://github.com/user-attachments/assets/8e4f43cd-550b-4041-bdc4-8764f400f99d" /> <br>


* Temperature : 27.85 C<br>
* Pressure    : 1005.32 hPa<br>

### 10. Key Concept
* If correct response is received → sensor is connected<br>
* If not → communication has failed<br>

### 11. Summary
* The code checks I2C connection using chip ID
* Initializes the BMP280 sensor
* Reads and prints temperature and pressure
* Runs continuously for real-time monitoring
