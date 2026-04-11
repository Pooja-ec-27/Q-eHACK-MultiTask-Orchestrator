'''c
  #include "rt_utils.h"
#include "config.h"
#include <sched.h>


void ts_step(struct timespec *t) //period is set to 1s
{
    t->tv_nsec += PERIOD_1S;

   
    if (t->tv_nsec >= NS_PER_SEC)
    //time in ns
    {
        t->tv_sec++;
        t->tv_nsec -= NS_PER_SEC;
    }
}


void rt_wait(struct timespec *t) {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, t, NULL);// monotonic clock where user cant change and gradually drifting
    ts_step(t);
}


void set_prio(int p) {
    struct sched_param sp = { .sched_priority = p };
    sched_setscheduler(0, SCHED_FIFO, &sp);// scheduling with fifo 
}
