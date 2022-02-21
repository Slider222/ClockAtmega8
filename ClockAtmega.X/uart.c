#include "funct.h"

void uartInit(uint16_t ubrr){        
    UBRRH = 0;//(unsigned char) (ubrr >> 8);
    UBRRL = 8;//(unsigned char) ubrr;
    UCSRB |= ( 1 << TXEN);
    UCSRC |= (1 << URSEL)|(1 << UCSZ0)| (1 << UCSZ1);    
}

void uartTransmit(uint8_t data){
    while ( !( UCSRA & (1<<UDRE)) );
    UDR = data;
}

void uartTransmit32(uint32_t data){
    for (int8_t i = 3; i > -1; i--){
       while ( !( UCSRA & (1<<UDRE)) );       
       UDR = (unsigned char) (data >> (i * 8));
              
    }
    
}