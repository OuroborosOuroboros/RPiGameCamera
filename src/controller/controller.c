/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * controller.c - controller module
 */

#include "controller.h"
#include "../model/camera.h"
#include "../model/led.h"
#include "../view/display.h"
#include "../model/photocell.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Static variable to determine mode as either image or video
static CaptureMode capture_mode = CAPTURE_MODE_IMAGE; // Default to image

// Change capture mode - Current options are image or video
void set_capture_mode(CaptureMode mode){
    if(mode == CAPTURE_MODE_IMAGE || mode == CAPTURE_MODE_VIDEO){
        capture_mode = mode;
    } else {
        log_message(LOG_ERROR, MSG_INVALID_CAPTURE_MODE, mode);
    }
}

/*
 * This method generates a filename, checks whether capture mode is image or video, then saves
 * the captured media to the filename. 
 */
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

/*
 * Helper method to check whether video or image is to be captured
 */
void capture_based_on_mode() {
    if (capture_mode == CAPTURE_MODE_IMAGE) {
        capture_media(BASE_DIR, "img", 0, "jpg", 0); // Duration is 0 for images
    } else if (capture_mode == CAPTURE_MODE_VIDEO) {
        capture_media(BASE_DIR, "vid", 1, "h264", VIDEO_DURATION_MS);
    }
}


/*
 * If motion is detected then helper methods are called to capture image or video
 */
void handle_motion(int gpio, int level, uint32_t tick){
    if(level == 1){
        log_message(LOG_INFO, MSG_MOTION_DETECTED, gpio, level, tick);

        // 1 for Dark, 0 for light
        int dark = is_dark();

        if(dark){
            // Turn on IR LED if it is dark
            led_on(IR_LED);
        }

        // Helper method to capture video or image
        capture_based_on_mode();

        // sleep for 3s        
        usleep(3000000);


        if(dark){
            // turn off IR LED after capture
            led_off(IR_LED);
        }
    }
}
