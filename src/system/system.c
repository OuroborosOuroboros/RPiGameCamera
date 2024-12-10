/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * system.c - system level operations 
 */

#include "system.h"
#include "../model/led.h"
#include "../model/sensor.h"
#include "../controller/controller.h"
#include "../view/display.h"
#include <pigpio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t signal_received = 0;

void sigint_handler(int signal){
    signal_received = 1;
}

void setup(){
    if(gpioInitialise() == PI_INIT_FAILED){
        log_message(LOG_ERROR, MSG_GPIO_INIT_FAILURE);
        exit(EXIT_FAILURE);
    }
    log_message(LOG_INFO, MSG_GPIO_INIT_SUCCESS);
    
    gpioSetMode(IR_LED, PI_OUTPUT);
    gpioWrite(IR_LED, PI_LOW);
    setup_sensor(PIR_SENSOR, handle_motion);
}

void cleanup(){
    gpioSetAlertFunc(PIR_SENSOR, NULL);
    gpioSetMode(PIR_SENSOR, PI_INPUT);
    gpioSetMode(IR_LED, PI_INPUT);
    gpioTerminate();
    log_message(LOG_INFO, MSG_GPIO_TERMINATED);
}