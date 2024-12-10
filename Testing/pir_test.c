/* Davey Getchell
 * 12/5/25
 * CS7680 - Final Project
 * pir_test.c - testing the PIR sensor 
 */

#include <pigpio.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h> // for sleep()
#include <time.h>

#define PIR_SENSOR 4
#define IR_LED 18

volatile sig_atomic_t signal_received = 0;

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
        fprintf(stderr, "ERROR: Failed to execute libcamera-still command \n");
        return -1;
    } else {
        printf("[INFO] Image captured successfully.\n");
        return 0;
    }
}

// Callback function for when motion is detected
void motion_detected(int gpio, int level, uint32_t tick){
    if(level == 1){
        printf("Motion detected! GPIO: %d, Level: %d, Tick: %u\n", gpio, level, tick);

        // Turn on LED
        gpioWrite(IR_LED, PI_HIGH);
        printf("[INFO] LED turned on.\n");

        // Generate filename
        char filename[150];
        generate_filename("/home/daveyg/media", "image", filename, sizeof(filename));
        if(capture_image(filename) == 0){
            printf("[INFO] Image saved as: %s\n", filename);
        } else {
            fprintf(stderr, "ERROR: Failed to capture image.\n")
        }

        // Keep LED on for 3 seconds
        usleep(3000000);

        gpioWrite(IR_LED, PI_LOW);
        printf("[INFO] LED turned off.\n");
    }
}

void sigint_handler(int signal){
    signal_received = 1;
}

void setup(){
    if(gpioInitialise() == PI_INIT_FAILED){
        fprintf(stderr, "ERROR: Failed to initialize GPIO interface...\n");
        exit(EXIT_FAILURE);
    }
    printf("[INIT] GPIO initialized successfully\n");

    gpioSetMode(IR_LED, PI_OUTPUT);
    gpioWrite(IR_LED, PI_LOW);
    gpioSetMode(PIR_SENSOR, PI_INPUT);
    gpioSetAlertFunc(PIR_SENSOR, motion_detected);
    printf("[SETUP] PIR sensor configured.\n");
}

void cleanup(){
    gpioSetAlertFunc(PIR_SENSOR, NULL);
    gpioSetMode(PIR_SENSOR, PI_INPUT);
    gpioSetMode(IR_LED, PI_INPUT);
    gpioTerminate();
    printf("\nGPIO terminated. Exiting...\n");
}

int main(){
    setup();

    signal(SIGINT, sigint_handler);
    
    while(!signal_received){
        sleep(1);
    }

    cleanup();

    return 0;
}

