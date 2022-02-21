
#ifndef UART_H
#define	UART_H

#define FOSC 16000000
#define BAUD 115200
#define MYUBRR FOSC/16/BAUD-1 

void uartInit(uint16_t ubrr);
void uartTransmit(uint8_t data);
void uartTransmit32(uint32_t data);

#endif	/* XC_HEADER_TEMPLATE_H */

