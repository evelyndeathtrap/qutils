#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>

#define PIT_TICK_RATE 1193180

int main() {
    // Open the console device to access the speaker hardware
    int fd = open("/dev/console", O_WRONLY);
    if (fd == -1) {
        perror("Error: Could not open /dev/console (Try running with sudo)");
        return 1;
    }

    int input_byte;

    // fgetc reads exactly one raw byte/char at a time from stdin until EOF
    while ((input_byte = fgetc(stdin)) != EOF) {
        
        // Map the 0-255 raw byte value to an audible frequency range (e.g., 200Hz - 2240Hz)
        int frequency = input_byte;

        if (frequency <= 0) {
            ioctl(fd, KIOCSOUND, 0);
        } else {
            /* KIOCSOUND expects a clock tick count instead of Hz.
             * Formula: counter = PIT_TICK_RATE / frequency
             */
            int counter = PIT_TICK_RATE / frequency;
            ioctl(fd, KIOCSOUND, counter);
        }

        // Keep the note playing for your 10 microsecond value
	usleep(10000); 
        // Mute the speaker briefly before the next raw byte arrives
        ioctl(fd, KIOCSOUND, 0);
    }

    // Ensure the speaker is off before exiting
    ioctl(fd, KIOCSOUND, 0);
    close(fd);
    return 0;
}
