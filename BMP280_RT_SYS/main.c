#include "config.h"
#include "rt_utils.h"
#include <stdio.h>
#include <signal.h>
#include <sys/mman.h>

/* Global run flag */
volatile int g_run = 1;

'''c
void on_signal(int s) {
    g_run = 0;
}

int main() {

  /mutex lock
    mlockall(MCL_CURRENT | MCL_FUTURE);

    
    set_prio(PRIO_ORCH);// high priority to orchestrator

  
    signal(SIGINT, on_signal);// interupt

    printf("BMP280 Real-Time System Started\n");
//creating new process

    while (g_run) {
        //system alive
    }

    printf("Shutting down...\n");

    return 0;
}
