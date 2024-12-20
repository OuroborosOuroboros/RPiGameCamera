/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * camera.h - camera module header
 */

#ifndef CAMERA_H

#define CAMERA_H

#include <stddef.h>

void generate_filename(const char *base_dir, const char *prefix, const char *extension, char *buffer, size_t size);
int capture_image(const char* filename);
int capture_video(const char* filename, int duration);

#endif // CAMERA_H 