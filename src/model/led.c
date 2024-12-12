/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * led.c - LED module
 */

#include "led.h"
#include <pigpio.h>
#include "../view/display.h"

// Turns on LEDs 
void led_on(int pin){
    gpioWrite(pin, PI_HIGH); // turns on LED
    log_message(LOG_INFO, MSG_LED_ON, pin); // prints message that LED turned on
}

// Turns off LEDs
void led_off(int pin){
    gpioWrite(pin, PI_LOW); // turns LED off
    log_message(LOG_INFO, MSG_LED_OFF, pin); // prints message that LED is off
}