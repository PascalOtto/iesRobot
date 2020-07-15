#include "linetracker.h"
#include <avr/io.h>

// AVCC as reference
#define REFS_SETTING 1
// use 125 kH
#define ADPS_SETTING 7

uint16_t threshold[] = {512, 512, 512};

void linetracker_init(void) {
    ADMUX   |= (REFS_SETTING << REFS0);
    ADCSRA  |= (1 << ADEN); // enable analog to digital converter
    ADCSRA  |= ADPS_SETTING;
}

int linetracker_measure_wait(linetracker_Tracker tracker) {
    ADMUX   = (ADMUX >> 4) << 4;    // clear MUX
    ADMUX   |= tracker;             // set MUX
    ADCSRA  |= (1 << ADSC);         // start measurement
    
    while((ADCSRA >> ADSC) & 1) {
        // wait
    }
    
    uint16_t readout = ADCW;
    return readout;
}

bool linetracker_is_triggered(linetracker_Tracker tracker) {
    uint16_t readout = linetracker_measure_wait(tracker);
    return readout >= threshold[tracker];
}
