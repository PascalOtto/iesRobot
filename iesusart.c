#include "iesusart.h"

/* Sets up the USART port (The USART Baud Rate Register). */
void USART_Init(unsigned long ubrr)
{
    // Set baud rate, high byte first
    UBRR0H = (unsigned char) (ubrr >> 8);
    
    // Set baud rate, low byte second
    UBRR0L = (unsigned char) ubrr;
    
    // Enable receiver/transmitter
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    
    // Frame format: 8 data, 2 stop bits
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}


/* Writes a single Byte to the USART transmit buffer. */
void USART_TransmitByte(unsigned char data)
{
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0))) {
        // Busy waiting! zzzZZZzzzZZZzzz
    }
    
    // Put data into buffer, send the data
    UDR0 = data;
}


/* Writes string to TX byte by byte until \0 reached. */
void USART_print(const char *c)
{
    while (*c != '\0') {
        USART_TransmitByte(*c);
        c++;
    }
}


/* Reads a single Byte out of the USART receive buffer.
 * A good way to use this would be calling it from an receive interrupt. */
unsigned char USART_ReceiveByte(void)
{
    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0))) {
        // Busy waiting! zzzZZZzzzZZZzzz
    }
    
    // Return received data from buffer
    return UDR0;
}
