/* Davey Getchell
 * CS7680
 * Final Project
 * main.c - driver for game camera 
 */

#include "system/system.h"
#include <unistd.h>

int main(){
    setup();

    signal(SIGINT, sigint_handler);
    
    while(!signal_received){
        sleep(1);
    }

    cleanup();

    return 0;
}

    