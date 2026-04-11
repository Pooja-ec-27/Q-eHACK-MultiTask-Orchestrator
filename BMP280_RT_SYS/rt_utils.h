'''c
#ifndef RT_UTILS_H
#define RT_UTILS_H

#include <time.h>// 1 sec forward

void ts_step(struct timespec *t);

void rt_wait(struct timespec *t);//


void set_prio(int p);// setting real time priority

#endif
