'''c
#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>


typedef struct
//structure for reading sensor
{
    float temp;
    float pressure;
    uint32_t sample_id;
    time_t timestamp;
} sensor_data_t;


void proc_sensor(void);// sensor process

#endif
