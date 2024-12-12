/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * photocell.c - photocell module to detect light
 */

#include "photocell.h"
#include "../view/display.h"
#include <pigpio.h>

// Reads data from photocell
int is_dark(){
    // Binary reading
    int reading = gpioRead(PHOTO_SENSOR);
    // prints reading and threshold to terminal
    log_message(LOG_INFO, MSG_PHOTOCELL_READING, reading, DARKNESS_THRESHOLD);
    return reading < DARKNESS_THRESHOLD; // Threshold is 1. Returns 1 if Dark and 0 if light
}