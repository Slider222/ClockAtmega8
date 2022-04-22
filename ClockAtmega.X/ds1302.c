#include "funct.h"

uint8_t bytes[8] = {0,0,0,0,0,0,0,0};

void RTC_SendByte(uint8_t byte){
    DDRD |= (1 << RTC_DAT);
    PORTD &= ~(1 << RTC_DAT);    
    for (uint8_t i = 0; i < 8; i++){
        if ((byte >> i) & 0x01)
		{
			PORTD |= (1 << RTC_DAT);
		}
		else PORTD &= ~(1 << RTC_DAT);		
		PORTD |= (1 << RTC_CLK);
		//asm("nop");
        _delay_us(3);
		PORTD &= ~(1 << RTC_CLK);
    }
}

 
uint8_t RTC_ReadByte(){    
    uint8_t result = 0; 
    DDRD &= ~(1 << RTC_DAT);
    for (uint8_t i = 0; i < 8; i++)
	{		 
		if (PIND & (1 << RTC_DAT)){                 
            result |= (1 << i);                                
        }
        PORTD |= (1 << RTC_CLK);
         //_delay_us(3);
		PORTD &= ~(1 << RTC_CLK);
		//asm("nop");
	}
	return result;    
}



void RTC_ReadClock(){
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(0xBF);
    for (uint8_t i = 0; i < 8; i++){
        bytes[i] = RTC_ReadByte();
    }
    PORTD &= ~(1 << RTC_CE);
}


void RTC_SetHour(uint8_t hours){
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(0x84);
    RTC_SendByte(hours);
    PORTD &= ~(1 << RTC_CE);    
    
}

void RTC_SetMin(uint8_t mins){
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(0x82);
    RTC_SendByte(mins);
    PORTD &= ~(1 << RTC_CE);    
    
}


void RTC_SetDay(uint8_t days){
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(0x86);
    RTC_SendByte(days);
    PORTD &= ~(1 << RTC_CE);    
    
}

void RTC_SetMounth(uint8_t mounth){
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(0x88);
    RTC_SendByte(mounth);
    PORTD &= ~(1 << RTC_CE);    
    
}

void RTC_SetYear(uint8_t years){
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(0x8c);
    RTC_SendByte(years);
    PORTD &= ~(1 << RTC_CE);    
    
}



void RTC_Unlock(){
    PORTD |= (1 << RTC_CE);
    RTC_SendByte(0x8e);
    RTC_SendByte(0x00);
    PORTD &= ~(1 << RTC_CE);
}






