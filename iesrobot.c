#include "config.h"
#include "led.h"
#include "iesusart.h"
#include "linetracker.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
    led_init();
    USART_Init(UBRR_SETTING);
    linetracker_init();
    
    while(1) {
        itoa(linetracker_measure_wait());
    }
}
