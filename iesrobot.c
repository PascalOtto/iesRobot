#include "config.h"
#include "led.h"
#include "iesusart.h"
#include "linetracker.h"
#include "motorcontrol.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
    led_init();
    USART_Init(UBRR_SETTING);
    linetracker_init();
    motorcontrol_init();
    
    motorcontrol_enable(true);
    
    uint32_t no_track_timeout = 2500;
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
    while(1) {
        bool left_triggered = linetracker_is_triggered(LEFTTRACKER);
        bool middle_triggered = linetracker_is_triggered(MIDTRACKER);
        bool right_triggered = linetracker_is_triggered(RIGHTTRACKER);
        if(left_triggered || middle_triggered || right_triggered) {
            no_track_timeout = 2500;
        }
        if(left_triggered && !right_triggered) { // steer left
            led_set_blue(true);
            led_set_green(false);
            led_set_yellow(false);
            motorcontrol_drive(BACKWARD, FORWARD);
        }
        else if(!left_triggered && right_triggered) { // steer right
            led_set_blue(false);
            led_set_green(false);
            led_set_yellow(true);
            motorcontrol_drive(FORWARD, BACKWARD);

        }
        else if(middle_triggered) { // forward
            led_set_blue(false);
            led_set_green(true);
            led_set_yellow(false);
            motorcontrol_drive(FORWARD, FORWARD);
        }
        else if(!left_triggered && !middle_triggered && !right_triggered) {
            no_track_timeout--;
            if(no_track_timeout <= 0) {
                motorcontrol_enable(false);
                led_set_green(true);
                led_set_yellow(true);
                led_set_blue(true);
            }
        }
    }
}
