/* Davey Getchell
 * CS7680
 * Final Project
 * main.c - driver for game camera 
 */

#include "src/system/system.h"
#include <unistd.h>

int main(){
    /* 
     *  Initialize GPIO and get pins ready
     * contains function to capture media when state changes from idle to motion detected
     */
    setup();

    // Gracefully exit if CTRL+C is entered
    signal(SIGINT, sigint_handler);
    
    // Loop to keep program running 
    // Default state is idle
    while(!signal_received){
        sleep(1);
    }

    // Set pins to safe state and terminate GPIO
    cleanup();

    // Exit program
    return 0;
}

    