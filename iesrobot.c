#include "config.h"
#include "led.h"
#include "iesusart.h"
#include "linetracker.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define UNK1_DDR    DDRD
#define UNK1_PORT   PORTD
#define UNK1_PIN    PD5

#define UNK2_DDR    DDRD
#define UNK2_PORT   PORTD
#define UNK2_PIN    PD7

#define UNK3_DDR    DDRB
#define UNK3_PORT   PORTB
#define UNK3_PIN    PB0

#define UNK4_DDR    DDRB
#define UNK4_PORT   PORTB
#define UNK4_PIN    PB1

#define UNK5_DDR    DDRB
#define UNK5_PORT   PORTB
#define UNK5_PIN    PB3

#define UNK6_DDR    DDRD
#define UNK6_PORT   PORTD
#define UNK6_PIN    PD6

int main(void)
{
    led_init();
    USART_Init(UBRR_SETTING);
    linetracker_init();
    
    UNK1_DDR |= (1 << UNK1_PIN);
    UNK2_DDR |= (1 << UNK2_PIN);
    UNK3_DDR |= (1 << UNK3_PIN);
    UNK4_DDR |= (1 << UNK4_PIN);
    UNK5_DDR |= (1 << UNK5_PIN);
    UNK6_DDR |= (1 << UNK6_PIN);
    
    
    
    /*while(1) {
        char readout [100];
        float voltage = linetracker_measure_wait(LEFTTRACKER) / 1024.f * 5.f;
        dtostrf(voltage, 3, 3, readout);
        USART_print("Measure1: ");
        USART_print(readout);
        USART_print("\n");
        
        voltage = linetracker_measure_wait(MIDTRACKER) / 1024.f * 5.f;
        dtostrf(voltage, 3, 3, readout);
        USART_print("Measure2: ");
        USART_print(readout);
        USART_print("\n");
        
        voltage = linetracker_measure_wait(RIGHTTRACKER) / 1024.f * 5.f;
        dtostrf(voltage, 3, 3, readout);
        USART_print("Measure3: ");
        USART_print(readout);
        USART_print("\n\n\n\n");
        
        _delay_ms(1000);
    }*/
    /*while(1) {
        bool left_triggered = linetracker_is_triggered(LEFTTRACKER);
        bool middle_triggered = linetracker_is_triggered(MIDTRACKER);
        bool right_triggered = linetracker_is_triggered(RIGHTTRACKER);
        if(left_triggered && !middle_triggered && !right_triggered) { // steer left
            led_set_blue(true);
            led_set_green(false);
            led_set_yellow(false);
        }
        else if(!left_triggered && !middle_triggered && right_triggered) { // steer right
            led_set_blue(false);
            led_set_green(false);
            led_set_yellow(true);
        }
        else if(middle_triggered) { // forward
            led_set_blue(false);
            led_set_green(true);
            led_set_yellow(false);
        }
        else {

        }
    }*/
    while(1) {
        unsigned char recv = USART_ReceiveByte();
        switch(recv) {
            case '1':
                UNK1_PORT ^= (1 << UNK1_PIN);
                break;
            case '2':
                UNK2_PORT ^= (1 << UNK2_PIN);
                break;
            case '3':
                UNK3_PORT ^= (1 << UNK3_PIN);
                break;
            case '4':
                UNK4_PORT ^= (1 << UNK4_PIN);
                break;
            case '5':
                UNK5_PORT ^= (1 << UNK5_PIN);
                break;
            case '6':
                UNK6_PORT ^= (1 << UNK6_PIN);
                break;
            case '\n': 
                break;
            default:
                USART_print("wrong input\n");
                break;
        }
    }
}
