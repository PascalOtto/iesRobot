#include "config.h"
#include "led.h"
#include "iesusart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
    led_init();
    USART_Init(UBRR_SETTING);
    
    while(1) {
        led_set_blue(true);
        char buffer [100];
        int i = 0;
        while(USART_ReceiveByte() != '\n') {
            i++;
            led_set_yellow(true);
        }
        char str[12];
        sprintf(str, "%d", i);
        USART_print(&str[0]);
        led_set_green(true);
    }
}
