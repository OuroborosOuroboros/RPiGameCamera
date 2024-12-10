/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * sensor.c - PIR sensor module
 */

#include "sensor.h"
#include "../view/display.h"
#include <pigpio.h>
#include <stdio.h>

void setup_sensor(int pin, gpioAlertFunc_t callback){
    gpioSetMode(pin, PI_INPUT);
    gpioSetAlertFunc(pin, callback);
    log_message(LOG_INFO, MSG_PIR_INIT);
}