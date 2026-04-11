#include "sensor.h"
#include "config.h"
#include "rt_utils.h"
#include "rpi_i2c.h"
#include <mqueue.h>
#include <time.h>
#include <unistd.h>


void proc_sensor(void)//sensor process
{

    set_prio(PRIO_SENSOR);// priority is set

    
    mqd_t mq = mq_open(MQ_S2A, O_WRONLY);// ipc mq

    uint32_t id = 0;

    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);// gradually increasing

    while (1)
      {

        sensor_data_t sd;// initialising

        sd.temp = 25.0;          /* Example value */
        sd.pressure = 1000.0;    /* Example value */

        sd.sample_id = ++id;
        sd.timestamp = time(NULL);

       
        mq_send(mq, (const char *)&sd, sizeof(sd), 1);//ipc inter process communication

      
        rt_wait(&t);// waiting
    }
}
