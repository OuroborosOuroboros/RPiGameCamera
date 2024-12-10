/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * display.h - view header file
 */

#ifndef DISPLAY_H

#define DISPLAY_H

// Log Levels
typedef enum {
    LOG_INFO,
    LOG_ERROR,
    LOG_WARNING
} LogLevel;

// Predefined log messages 
typedef enum {
    MSG_GPIO_INIT_SUCCESS,
    MSG_GPIO_INIT_FAILURE,
    MSG_MOTION_DETECTED,
    MSG_IMAGE_CAPTURED,
    MSG_IMAGE_CAPTURED_FAILED,
    MSG_VIDEO_CAPTURED,
    MSG_VIDEO_CAPTURED_FAILED,
    MSG_INVALID_CAPTURE_MODE,
    MSG_LED_ON,
    MSG_LED_OFF,
    MSG_PIR_INIT,
    MSG_GPIO_TERMINATED
} LogMessage;

// Function to log messages
void log_message(LogLevel level, LogMessage message, ...);

#endif 