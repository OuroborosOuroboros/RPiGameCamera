/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * controller.c - controller module
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

#define IR_LED 18
#define BASE_DIR "/home/daveyg/media"
#define FILENAME_BUFFER_SIZE 256
#define VIDEO_DURATION_MS 150000 // 15 seconds

typedef enum {
    CAPTURE_MODE_IMAGE = 0,
    CAPTURE_MODE_VIDEO = 1
} CaptureMode;

void set_capture_mode(CaptureMode mode);
void capture_media(const char *base_dir, const char *prefix, int is_video, const char *extension, int duration);
void handle_motion(int gpio, int level, uint32_t tick);

#endif // CONTROLLER_H