
```c

#ifndef CONFIG_H
#define CONFIG_H

/* ================= BMP280 CONFIGURATION ================= */

/* I2C address of BMP280 sensor */
#define BMP280_ADDR 0x76

/* Raspberry Pi I2C bus */
#define I2C_BUS 1

/* Standard sea-level pressure (used for altitude calculation) */
#define SEA_LEVEL_HPA 1013.25f


/* ================= REAL-TIME PRIORITIES ================= */
/* Higher value = higher priority (SCHED_FIFO scheduling) */

#define PRIO_ORCH      25   /* Orchestrator (highest control) */
#define PRIO_SENSOR    20   /* Sensor reading */
#define PRIO_ANALYTICS 18   /* Data processing */
#define PRIO_DISPLAY   15   /* Display output */
#define PRIO_ALARM     15   /* Alarm handling */
#define PRIO_LOGGER    12   /* File logging */


/* ================= TIMING ================= */

/* 1 second in nanoseconds */
#define NS_PER_SEC 1000000000LL
#define PERIOD_1S  NS_PER_SEC


/* ================= ALARM THRESHOLDS ================= */

/* Trigger alarm if temperature too high */
#define ALARM_TEMP_HIGH 45.0f

/* Trigger alarm if pressure too low */
#define ALARM_PRESS_LOW 900.0f


/* ================= IPC (INTER-PROCESS COMMUNICATION) ================= */

/* Message queue names */
#define MQ_S2A  "/mq_s2a"   /* Sensor → Analytics */
#define MQ_A2D  "/mq_a2d"   /* Analytics → Display */
#define MQ_A2AL "/mq_a2al"  /* Analytics → Alarm */

/* Shared memory name */
#define SHM_NAME "/shm_bmp280"

/* Message queue depth */
#define MQ_DEPTH 8
'''

#endif
