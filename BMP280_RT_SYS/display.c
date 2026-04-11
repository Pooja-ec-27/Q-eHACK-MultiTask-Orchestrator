#include "analytics.h"
#include "config.h"
#include <mqueue.h>
'''c
#include <stdio.h>

/*

void proc_display(void) //formatted o/p
{

    set_prio(PRIO_DISPLAY);

    mqd_t mq = mq_open(MQ_A2D, O_RDONLY);

    while (1) {

        analytics_data_t ad;

        if (mq_receive(mq, (char *)&ad, sizeof(ad), NULL) > 0) {

            printf("Sample #%u\n", ad.raw.sample_id);
            printf("Temp: %.2f C\n", ad.raw.temp);
            printf("Pressure: %.2f hPa\n", ad.raw.pressure);
            printf("Altitude: %.2f m\n", ad.altitude);

            if (ad.alarm_active)
                printf("⚠️ ALARM TRIGGERED!\n");

            printf("-----------------------------\n");
        }
    }
}
