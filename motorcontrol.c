#include "motorcontrol.h"
#include <avr/io.h>

#define LEFT_EN_DDR     DDRD
#define LEFT_EN_PORT    PORTD
#define LEFT_EN_PIN     PD5

#define RIGHT_EN_DDR    DDRD
#define RIGHT_EN_PORT   PORTD
#define RIGHT_EN_PIN    PD6

#define LEFT_FW_DDR     DDRD
#define LEFT_FW_PORT    PORTD
#define LEFT_FW_PIN     PD7

#define LEFT_BW_DDR     DDRB
#define LEFT_BW_PORT    PORTB
#define LEFT_BW_PIN     PB0

#define RIGHT_BW_DDR    DDRB
#define RIGHT_BW_PORT   PORTB
#define RIGHT_BW_PIN    PB1

#define RIGHT_FW_DDR    DDRB
#define RIGHT_FW_PORT   PORTB
#define RIGHT_FW_PIN    PB3

void motorcontrol_init(void) {
    // set data direction registers
    UNK1_DDR |= (1 << UNK1_PIN);
    UNK2_DDR |= (1 << UNK2_PIN);
    UNK3_DDR |= (1 << UNK3_PIN);
    UNK4_DDR |= (1 << UNK4_PIN);
    UNK5_DDR |= (1 << UNK5_PIN);
    UNK6_DDR |= (1 << UNK6_PIN);
}

void motorcontrol_enable(bool enable) {
    if(enable) {
        LEFT_EN_PORT |= (1 << LEFT_EN_PIN);
        RIGHT_EN_PORT |= (1 << RIGHT_EN_PIN);
    }
    else {
        LEFT_EN_PORT &= ~(1 << LEFT_EN_PIN);
        RIGHT_EN_PORT &= ~(1 << RIGHT_EN_PIN);
    }
}

void motorcontrol_drive(motorcontrol_direction left, motorcontrol_direction right) {
    LEFT_BW_PORT &= ~(1 << LEFT_BW_PIN);
    LEFT_FW_PORT &= ~(1 << LEFT_FW_PIN);
    LEFT_BW_PORT &= ~(1 << LEFT_BW_PIN);
    LEFT_FW_PORT &= ~(1 << LEFT_FW_PIN);
    
    if(left == FORWARD) {
        LEFT_FW_PORT |= (1 << LEFT_FW_PIN);
    }
    else if(left == BACKWARDS) {
        LEFT_BW_PORT |= (1 << LEFT_BW_PIN);
    }
    
    if(right == FORWARD) {
        RIGHT_FW_PORT |= (1 << RIGHT_FW_PIN);
    }
    else if(right == BACKWARDS) {
        RIGHT_BW_PORT |= (1 << RIGHT_BW_PIN);
    }
}

void motorcontrol_stop(void) {
    motorcontrol_drive(STOP, STOP);
}
