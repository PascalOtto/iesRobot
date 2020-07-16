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
    
    uint32_t no_track_timeout = 5000;
    motorcontrol_direction prev_left = STOP;
    motorcontrol_direction prev_right = STOP;
    while(1) {
        bool left_triggered = linetracker_is_triggered(LEFTTRACKER);
        bool middle_triggered = linetracker_is_triggered(MIDTRACKER);
        bool right_triggered = linetracker_is_triggered(RIGHTTRACKER);
        if(left_triggered || middle_triggered || right_triggered) {
            no_track_timeout = 5000;
        }
        if(left_triggered && !right_triggered) { // steer left
            led_set_blue(true);
            led_set_green(false);
            led_set_yellow(false);
            prev_left = BACKWARD;
            prev_right = FORWARD;
            motorcontrol_drive(prev_left, prev_right);
        }
        else if(!left_triggered && right_triggered) { // steer right
            led_set_blue(false);
            led_set_green(false);
            led_set_yellow(true);
            prev_left = FORWARD;
            prev_right = BACKWARD;
            motorcontrol_drive(prev_left, prev_right);

        }
        else if(middle_triggered && !left_triggered && !right_triggered) { // forward
            led_set_blue(false);
            led_set_green(true);
            led_set_yellow(false);
            motorcontrol_drive(FORWARD, FORWARD);
        }
        else if(!left_triggered && !middle_triggered && !right_triggered) { // no track detected
            no_track_timeout--;
            if(no_track_timeout >= 3500) {
                
            }
            else if(no_track_timeout <= 3500) {
                motorcontrol_drive(prev_left, prev_right);
            }
            if(no_track_timeout <= 0) {
                motorcontrol_enable(false);
                led_set_green(true);
                led_set_yellow(true);
                led_set_blue(true);
            }
        }
    }
}
