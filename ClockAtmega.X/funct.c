#include "funct.h"

extern volatile uint64_t ticks;


void timerInit(){
	TCNT0 = 6;                 
	TIMSK |= (1 << TOIE0);    
	TCCR0 |= (1 << CS11)|(1 << CS10);	

}

uint64_t ticks_ms(){
    uint64_t ticksReturn = 0;
	ATOMIC_BLOCK(ATOMIC_FORCEON){  	
        ticksReturn = ticks;		
	}
    return ticksReturn;	
}



