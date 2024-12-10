/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * controller.c - controller module
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#define IR_LED 18
#define BASE_DIR "/home/daveyg/media"

void handle_motion(int gpio, int level, uint32_t tick);

#endif