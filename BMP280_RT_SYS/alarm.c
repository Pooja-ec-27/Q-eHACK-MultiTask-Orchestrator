'''c
#include "analytics.h"
#include "config.h"
#include <mqueue.h>
#include <stdio.h>

void proc_alarm(void) // alarm condition
{

    set_prio(PRIO_ALARM);

    mqd_t mq = mq_open(MQ_A2AL, O_RDONLY);

    while (1) {

        analytics_data_t ad;

        if (mq_receive(mq, (char *)&ad, sizeof(ad), NULL) > 0) {

            fprintf(stderr,
                "[ALARM] Sample #%u | Temp=%.2f | Pressure=%.2f\n",
                ad.raw.sample_id,
                ad.raw.temp,
                ad.raw.pressure);
        }
    }
}
