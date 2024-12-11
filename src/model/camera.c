/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * camera.c - camera module
 */

#include "camera.h"
#include "../view/display.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Generate unique filename for media
void generate_filename(const char *base_dir, const char *prefix, const char *extension, char *buffer, size_t size){
   // Get current date in "YYMMDD" format
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Generate Filename
    snprintf(buffer, size, "%s/%s_%02d%02d%02d_%02d%02d%02d.%s", base_dir, prefix, 
            t->tm_year %100, t->tm_mon +1, t->tm_mday, t->tm_hour, 
            t->tm_min, t->tm_sec, extension);
}

// Capture an image
int capture_image(const char* filename){
    char command[200];
    snprintf(command, sizeof(command), "libcamera-still -o %s --timeout 1000 > /dev/null 2>&1", filename);
    int ret = system(command);
    if (ret == -1){
        log_message(LOG_ERROR, MSG_IMAGE_CAPTURED_FAILED);
        return -1;
    } else {
        log_message(LOG_INFO, MSG_IMAGE_CAPTURED, filename);
        return 0;
    }
}

// Capture a video
int capture_video(const char* filename, int duration){
    char command[200];
    snprintf(command, sizeof(command), "libcamera-vid -o %s --timeout %d > /dev/null 2>&1", filename, duration);
    int ret = system(command);
    if (ret == -1){
        log_message(LOG_ERROR, MSG_VIDEO_CAPTURED_FAILED);
        return -1;
    } else {
        log_message(LOG_INFO, MSG_VIDEO_CAPTURED, filename);
        return 0;
    }
}