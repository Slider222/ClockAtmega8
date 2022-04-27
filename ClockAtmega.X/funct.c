#include "funct.h"

volatile uint32_t _ticks;


void port_init()
{	
	DDRB |= (1 << PORTB0);    
    DDRD |= (1 << PORTD5) | (1 << RTC_CLK) | (1 << RTC_DAT) | (1 << RTC_CE);
    //DDRC |= (1 << PORTC0) | (1 << PORTC1);
	
	
	DDRB |= (1 << clockInput) | (1 << dataInput) | (1 << dataEnable1) | (1 << dataEnable2) | (1 << PWM_OUT);
	PORTB |= (1 << dataEnable1) | (1 << dataEnable2);
    
    
    
    
	
	
}

void timerInit(){
	TCNT0 = 7;                 
	TIMSK |= (1 << TOIE0);    
	TCCR0 |= (1 << CS11)|(1 << CS10);	
    
    
    TCNT2 = 0;                                           
	TIMSK |= (1 << OCIE2);                               
	TCCR2 |= (1 << WGM21);                
	                              

}

uint32_t ticks_ms(){
    //uint64_t ticksReturn = 0;
	ATOMIC_BLOCK(ATOMIC_FORCEON){  	
        //ticksReturn = ticks;   
        return _ticks;
	}    	
}



uint8_t hexToBin(uint8_t data){
    uint8_t rezult = ((((data & 0xF0) >> 4) * 10) + (data & 0x0f));
    return rezult;
}

uint8_t binToHex(uint8_t data){
   uint8_t rezult = ((data/10) << 4) + data % 10;
   return rezult;   
}
