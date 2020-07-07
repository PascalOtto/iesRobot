#include "led.h"

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
}

void writeToShiftRegister() {
    
}

void led_set_blue(bool on) {
    led_blue = on;
    writeToShiftRegister();
}

void led_set_yellow(bool on) {
    led_yellow = on;
    writeToShiftRegister();
}

void led_set_green(bool on) {
    led_blue = on;
    writeToShiftRegister();
}