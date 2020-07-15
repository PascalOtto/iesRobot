#include "led.h"
#include <avr/io.h>

#define DATA_DDR    DDRB
#define DATA_PORT   PORTB
#define DATA_PIN    PB2
#define CLK_DDR     DDRD
#define CLK_PORT    PORTD
#define CLK_PIN     PD4

bool led_yellow = false;
bool led_green = false;
bool led_blue = false;

void led_init() {
    // Direction
    DATA_DDR |= (1 << DATA_PIN);
    CLK_DDR  |= (1 << CLK_PIN);
    led_set_green(false);
    led_set_yellow(false);
    led_set_blue(false);
}

void shiftValue(bool value) {
    CLK_PORT &= ~(1 << CLK_PIN);
    if(value == true) {
        DATA_PORT |= (1 << DATA_PIN);
    }
    else {
        DATA_PORT &= ~(1 << DATA_PIN);
    }
    CLK_PORT |= (1 << CLK_PIN);
}

void writeToShiftRegister() {
    shiftValue(led_blue);
    shiftValue(led_green);
    shiftValue(led_yellow);
}

void led_set_blue(bool on) {
    bool changed = led_blue != on;
    led_blue = on;
    if(changed) {
        writeToShiftRegister();
    }
}

void led_set_yellow(bool on) {
    bool changed = led_yellow != on;
    led_yellow = on;
    if(changed) {
        writeToShiftRegister();
    }
}

void led_set_green(bool on) {
    bool changed = led_green != on;
    led_green = on;
    if(changed) {
        writeToShiftRegister();
    }
}