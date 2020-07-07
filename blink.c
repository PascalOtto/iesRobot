#include "config.h"
#include "led.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    led_init();
    
    _delay_ms(1000);
    led_set_green(true);
    led_set_yellow(false);
    led_set_blue(false);
    _delay_ms(1000);
    
        _delay_ms(1000);
    led_set_green(false);
    led_set_yellow(false);
    led_set_blue(true);
    _delay_ms(1000);
    
        _delay_ms(1000);
    led_set_green(false);
    led_set_yellow(true);
    led_set_blue(false);
    _delay_ms(1000);
    
            _delay_ms(1000);
    led_set_green(true);
    led_set_yellow(true);
    led_set_blue(false);
    _delay_ms(1000);
    
            _delay_ms(1000);
    led_set_green(true);
    led_set_yellow(true);
    led_set_blue(true);
    _delay_ms(1000);
}