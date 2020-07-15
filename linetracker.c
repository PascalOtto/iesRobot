#include "linetracker.h"
#include <avr/io.h>

// AVCC as reference
#define REFS_SETTING 1
// use 125 kH
#define ADPS_SETTING 7

#define MUXSENSOR1 0
#define MUXSENSOR2 1
#define MUXSENSOR3 2

void linetracker_init(void) {
    ADMUX   |= (REFS_SETTING << REFS0);
    ADCSRA  |= (1 << ADEN); // enable analog to digital converter
    ADCSRA  |= ADPS_SETTING;
}

int linetracker_measure_wait() {
    ADMUX   |= MUXSENSOR1;
    ADCSRA  |= (1 << ADSC); // start measurement
    
    while((ADCSRA >> ADSC) & 1) {
        // wait
    }
    
    uint16_t readout = ADCW;
    
}
