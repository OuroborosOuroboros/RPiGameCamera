/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * system.h - system-level operations header
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#define PIR_SENSOR 4

#include <signal.h>

void sigint_handler(int signal);

void setup();

void cleanup();

extern volatile sig_atomic_t signal_received;

#endif