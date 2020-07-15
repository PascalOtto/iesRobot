#include "linetracker.h"
#include <avr/io.h>

// AVCC as reference
#define REFS 1

#define MUXSENSOR1
#define MUXSENSOR2
#define MUXSENSOR3

void linetracker_init(void) {
    ADMUX |= (REFS << 6);
}
