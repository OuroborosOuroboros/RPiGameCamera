/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * sensor.c - PIR sensor module
 */

#include "sensor.h"
#include "../view/display.h"
#include <pigpio.h>
#include <stdio.h>

/*
 * This method sets the PIR sensor pin to read input
 * and then calls a function when movement is detected
 */
void setup_sensor(int pin, gpioAlertFunc_t callback){
    gpioSetMode(pin, PI_INPUT);
    // Registers pin to call a function when the pin changes state
    gpioSetAlertFunc(pin, callback);
    log_message(LOG_INFO, MSG_PIR_INIT); // Message confirms PIR initialized
}