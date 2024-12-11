/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * photocell.c - photocell module to detect light
 */

#include "photocell.h"
#include "view/display.h"
#include <pigpio.h>

int is_dark(){
    int reading = gpioRead(PHOTO_SENSOR);
    log_message(LOG_INFO, MSG_PHOTOCELL_READING);
    return reading < DARKNESS_THRESHOLD;
}