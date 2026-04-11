#include "analytics.h"
#include "config.h"
#include <mqueue.h>
#include <math.h>

/
static analytics_data_t process(sensor_data_t *raw)// raw data is converted to pressure , altitude and temp
{

    static float prev_pressure = 0;

    analytics_data_t ad;
    ad.raw = *raw;

  
    ad.altitude = 44330.0f *// barometric formula
        (1.0f - pow(raw->pressure / SEA_LEVEL_HPA, 0.1903f));

    
    ad.trend_delta = raw->pressure - prev_pressure;// rising or falling pressure
    prev_pressure = raw->pressure;

 
    ad.alarm_active = // ararm
        (raw->temp >= ALARM_TEMP_HIGH ||
         raw->pressure <= ALARM_PRESS_LOW);

    return ad;
}

void proc_analytics(void) {

    set_prio(PRIO_ANALYTICS);

    mqd_t mi = mq_open(MQ_S2A, O_RDONLY);
    mqd_t mo = mq_open(MQ_A2D, O_WRONLY);

    while (1) {

        sensor_data_t sd;

        if (mq_receive(mi, (char *)&sd, sizeof(sd), NULL) > 0) {

            analytics_data_t ad = process(&sd);

       // send process delay
            mq_send(mo, (const char *)&ad, sizeof(ad), 1);
        }
    }
}
