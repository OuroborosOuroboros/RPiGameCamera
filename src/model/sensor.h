/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * sensor.h - PIR sensor module header
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <pigpio.h>

void setup_sensor(int pin, gpioAlertFunc_t callback);

#endif // SENSOR_H