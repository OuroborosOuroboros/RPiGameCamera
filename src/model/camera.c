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


void generate_filename(const char *base_dir, const char *prefix, char *buffer, size_t size){
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    snprintf(buffer, size, "%s/%s_%04d%02d%02d_%02d%02d%02d.jpg",
            base_dir, prefix, 
            t->tm_year + 1900, t->tm_mon +1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);
}



int capture_image(const char* filename){
    char command[200];
    snprintf(command, sizeof(command), "libcamera-still -o %s --timeout 1000", filename);
    int ret = system(command);
    if (ret == -1){
        log_message(LOG_ERROR, MSG_IMAGE_CAPTURED_FAILED);
        return -1;
    } else {
        log_message(LOG_INFO, MSG_IMAGE_CAPTURED, filename);
        return 0;
    }
}