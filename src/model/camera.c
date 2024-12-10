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

// Helper function: Update date and reset counter if needed
void update_date_and_reset_counter(char *last_date, size_t date_size, int *counter){
    // Get current date in "YYMMDD" format
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char current_date[9];
    snprintf(current_date, sizeof(current_date), "%02d%02d%02d", 
            t->tm_year % 100, t->tm_mon +1, t->tm_mday);
    
    // Check if date has changed
    if(strcmp(last_date, current_date) !=0) {
        // Reset counter and update last_date
        counter = 0;
        strncpy(last_date, current_date, sizeof(last_date));
    }
}

// Generate unique filename for media
void generate_filename(const char *base_dir, const char *prefix, const char *extension, char *buffer, size_t size){
    static int counter = 0;        // Persistent counter
    static char last_date[9] = ""; // Persistent last date in "YYMMDD" format

    update_date_and_reset_counter(last_date, sizeof(last_date), &counter);

    // Generate Filename
    snprintf(buffer, size, "%s/%s_%s_%03d.%s", base_dir, prefix, last_date, counter++, extension);
}

// Capture an image
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

// Capture a video
int capture_video(const char* filename, int duration){
    char command[200];
    snprintf(command, sizeof(command), "libcamera-vid -o %s --timeout %d", filename, duration);
    int ret = system(command);
    if (ret == -1){
        log_message(LOG_ERROR, MSG_VIDEO_CAPTURED_FAILED);
        return -1;
    } else {
        log_message(LOG_INFO, MSG_VIDEO_CAPTURED, filename);
        return 0;
    }
}