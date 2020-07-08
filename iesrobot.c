#include "config.h"
#include "led.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    led_init();
    USART_Init();
}