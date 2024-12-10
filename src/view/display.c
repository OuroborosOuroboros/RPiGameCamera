/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * display.c - view file
 */

#include "display.h"
#include <stdio.h>
#include <stdarg.h>

// Predefined log messages
static const char *log_templates[] = {
    [MSG_GPIO_INIT_SUCCESS] = "GPIO initialized successfully.",
    [MSG_GPIO_INIT_FAILURE] = "Failed to initialize GPIO interface.",
    [MSG_MOTION_DETECTED] = "Motion detected! GPIO: %d, Level: %d, Tick: %u",
    [MSG_IMAGE_CAPTURED] = "Image captured successfully: %s",
    [MSG_IMAGE_CAPTURED_FAILED] = "Failed to capture image.",
    [MSG_VIDEO_CAPTURED] = "Video captured successfully: %s",
    [MSG_VIDEO_CAPTURED_FAILED] = "Failed to capture video",
    [MSG_INVALID_CAPTURE_MODE] = "Invalid capture mode selected.",
    [MSG_LED_ON] = "LED turned on (GPIO %d).",
    [MSG_LED_OFF] = "LED turned off (GPIO %d).",
    [MSG_PIR_INIT] = "PIR Sensor configured.",
    [MSG_GPIO_TERMINATED] = "GPIO terminated. Exiting...",
    [MSG_PHOTOCELL_READING] = "Photocell reading: %d (Threshold: %d)"
};

void log_message(LogLevel level, LogMessage message, ...){
    // Prefix for log levels
    const char *level_prefix;
    switch (level){
        case LOG_INFO:      level_prefix = "[INFO]"; break;
        case LOG_ERROR:     level_prefix = "[ERROR]"; break;
        case LOG_WARNING:   level_prefix = "[WARNING]"; break;
        default:            level_prefix = "[LOG]"; break;
    }

    // Print log level
    printf("%s", level_prefix);

    // Print formatted message
    va_list args;
    va_start(args, message);
    vprintf(log_templates[message], args);
    va_end(args);

    // Append newline for readability
    printf("\n");
}