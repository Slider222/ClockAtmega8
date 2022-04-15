#include "funct.h"


void RTC_SendByte(uint8_t byte){    
    for (uint8_t i = 0; i < 8; i++){
        if ((byte & 0x01) == 0x00)
		{
			PORTC &= ~(1 << RTC_DAT);
		}
		else PORTC |= (1 << RTC_DAT);
		byte = byte >> 1;
		PORTB |= (1 << RTC_CLK);
		//asm("nop");
		PORTB &= ~(1 << RTC_CLK);
    }
}


uint8_t RTC_ReadByte(){    
    uint8_t result = 0;    
    for (uint8_t i = 0; i < 8; i ++)
	{
		PORTC |= (1 << RTC_CLK);                           //????? ?? ????? SCK	
        result = result << 1;
		if ((PINC & (1 << RTC_DAT)) != 0x00){                 //??????? ????? ??? ? ??????? ????¤?
            result = result | 0x01;                                //??????? ????????? ? ????? ????? MISO ???
        }       
		PORTC &= ~(1 << RTC_CLK);
		//asm("nop");
	}
	return result;    
}

uint8_t RTC_ReadReg(uint8_t adresse){
    uint8_t dataReg = 0;
    PORTC |= (1 << RTC_CE);
    RTC_SendByte(adresse);
    DDRC &= ~(1 << RTC_DAT);
    dataReg = RTC_ReadByte();
    DDRC |= (1 << RTC_DAT);
    PORTC &= ~(1 << RTC_CE);
    return dataReg;
}






