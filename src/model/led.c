/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * led.c - LED module
 */

#include "led.h"
#include <pigpio.h>
#include "../view/display.h"

void led_on(int pin){
    gpioWrite(pin, PI_HIGH);
    log_message(LOG_INFO, MSG_LED_ON, pin);
}

void led_off(int pin){
    gpioWrite(pin, PI_LOW);
    log_message(LOG_INFO, MSG_LED_OFF, pin);
}