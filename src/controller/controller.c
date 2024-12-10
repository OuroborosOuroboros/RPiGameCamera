/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * controller.c - controller module
 */

#include "controller.h"
#include "../model/camera.h"
#include "../model/led.h"
#include "../view/display.h"
#include <stdint.h>
#include <stdio.h>



void handle_motion(int gpio, int level, uint32_t tick){
    if(level == 1){
        log_message(LOG_INFO, MSG_MOTION_DETECTED, gpio, level, tick);

        led_on(IR_LED);

        char filename[150];
        generate_filename(BASE_DIR, "image", filename, sizeof(filename));
        capture_image(filename);

        usleep(3000000);

        led_off(IR_LED);
    }
}
