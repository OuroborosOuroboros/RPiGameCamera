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
#include <string.h>


static CaptureMode capture_mode = CAPTURE_MODE_IMAGE; // Default to image

// Change capture mode - Current options are image or video
void set_capture_mode(CaptureMode mode){
    if(mode == CAPTURE_MODE_IMAGE || mode == CAPTURE_MODE_VIDEO){
        capture_mode = mode;
    } else {
        log_message(LOG_ERROR, MSG_INVALID_CAPTURE_MODE, mode);
    }
}

void capture_media(const char *base_dir, const char *prefix, int is_video, const char *extension, int duration){
    char filename[FILENAME_BUFFER_SIZE];
    generate_filename(base_dir, prefix, extension, filename, sizeof(filename));

    if (is_video) {
        if(capture_video(filename, duration) != 0) {
            log_message(LOG_ERROR, MSG_VIDEO_CAPTURED_FAILED);
        }
    } else {
        if(capture_image(filename)!=0){
            log_message(LOG_ERROR, MSG_IMAGE_CAPTURED_FAILED);
        }
    }
}

void handle_motion(int gpio, int level, uint32_t tick){
    if(level == 1){
        log_message(LOG_INFO, MSG_MOTION_DETECTED, gpio, level, tick);

        led_on(IR_LED);

        if(capture_mode == CAPTURE_MODE_IMAGE){
            capture_media(BASE_DIR, "img", 0, "jpg");
        } else if (capture_mode == CAPTURE_MODE_VIDEO) {
            capture_media(BASE_DIR, "vid", 1, VIDEO_DURATION_MS, "h264");
        }
            
        usleep(3000000);

        led_off(IR_LED);
    }
}
