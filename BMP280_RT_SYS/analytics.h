'''c
  #ifndef ANALYTICS_H
#define ANALYTICS_H 

#include "sensor.h"


typedef struct// analysing the data
{
    sensor_data_t raw;
    float altitude;
    float trend_delta;
    int alarm_active;
} analytics_data_t;

void proc_analytics(void);

#endif
