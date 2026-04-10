# BMP280 I2C Sensor Test (QNX RTOS)

## Overview
This module validates I2C communication between Raspberry Pi and BMP280 sensor 
under QNX RTOS environment.

## Objective
- Verify I2C bus functionality
- Read real-time temperature and pressure data
- Establish reliable sensor communication for orchestrator integration

## Design Approach

The implementation is divided into 3 layers:

1. Application Layer (main.c)
   → Controls execution flow and output

2. Driver Layer (bmp280.c)
   → Handles sensor-specific logic and calibration

3. Hardware Abstraction Layer (i2c_wrapper.c)
   → Manages low-level I2C communication

## Key Features

- Sensor auto-detection via Chip ID
- Calibration-based accurate readings
- Continuous real-time monitoring
- Modular and reusable architecture

## Why This Matters for RTOS

This module acts as:
→ Sensor Task prototype for orchestrator
→ Real-time data source
→ Input pipeline for analytics process

## Output

Example:
Temperature : 27.45 C  
Pressure    : 1002.31 hPa  

## Future Integration

This module will be integrated into:
- Sensor Process (Multi-process orchestrator)
- Shared memory pipeline
- Real-time analytics system
