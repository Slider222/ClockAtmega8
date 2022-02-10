#include "funct.h"

extern volatile uint64_t ticks;


void timerInit(){
	TCNT0 = 125;                 
	TIMSK |= (1 << TOIE0);    
	TCCR0 |= (1 << CS01);	

}

uint64_t ticks_ms(){
    uint64_t ticksReturn = 0;
	ATOMIC_BLOCK(ATOMIC_FORCEON)
	{  	
        ticksReturn = ticks;		
	}
    return ticksReturn;	
}



