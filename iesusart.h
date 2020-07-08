#ifndef IESUSART
#define IESUSART

#include <avr/io.h>
#define BAUD 9600 // Desired Baud Rate
#define UBRR_SETTING F_CPU/16.0/BAUD-1 // What to write into the UBRR

unsigned char USART_ReceiveByte(void);
void USART_print(const char *c);
void USART_TransmitByte(unsigned char data);
void USART_Init(unsigned long ubrr);

#endif
