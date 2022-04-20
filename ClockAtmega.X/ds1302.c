#include "funct.h"


void RTC_SendByte(uint8_t byte){    
    for (uint8_t i = 0; i < 8; i++){
        if ((byte & 0x01) == 0x00)
		{
			PORTD &= ~(1 << RTC_DAT);
		}
		else PORTD |= (1 << RTC_DAT);
		byte = byte >> 1;
		PORTD |= (1 << RTC_CLK);
		//asm("nop");
		PORTD &= ~(1 << RTC_CLK);
    }
}


uint8_t RTC_ReadByte(){    
    uint8_t result = 0;    
    for (uint8_t i = 0; i < 8; i ++)
	{
		PORTD |= (1 << RTC_CLK);                           //????? ?? ????? SCK	
        result = result << 1;
		if ((PIND & (1 << RTC_DAT)) != 0x00){                 //??????? ????? ??? ? ??????? ????¤?
            result = result | 0x01;                                //??????? ????????? ? ????? ????? MISO ???
        }       
		PORTD &= ~(1 << RTC_CLK);
		//asm("nop");
	}
	return result;    
}

uint8_t RTC_ReadReg(uint8_t adresse){
    uint8_t dataReg = 0;
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(adresse);
    DDRD &= ~(1 << RTC_DAT);
    dataReg = RTC_ReadByte();
    DDRD |= (1 << RTC_DAT);
    PORTD &= ~(1 << RTC_CE);
    return dataReg;
}






