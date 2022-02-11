#include "funct.h"


volatile uint64_t ticks = 0;
volatile uint32_t curentTime = 0;

#define ONE              1
#define TWO              2
#define THREE            3
#define FOUR             4

int main(void) {
    port_init();
    timerInit();
    uint8_t hours = 12, mins = 24, secs = 0;
    sei();
    uint32_t prevtime1 = 0;
    uint8_t key = 0, statusReg = 0, keyTrig = 0;
    
    
    
    while (1) {
    curentTime = ticks_ms();
    key = getKey();
    keyTrig = trig_button();

    if (keyTrig == ONE){
       hours++; 
    }
    if (keyTrig == TWO){
       mins++; 
    }
    
    if (key == THREE){
       mins = mins + 1; 
    }

    
    if (curentTime - prevtime1 >= 1000){
        secs++;
        sendClock(hours, mins, secs);
        prevtime1 = curentTime;
    }        
        
    if (secs == 60){
           secs = 0;
           mins = mins + 1;
       }
       if (mins == 60){
           mins = 0;
           hours = hours + 1;
       }
       if (hours == 24){
           hours = 0;
       }     
      
        
    
        
        
     
        
    }
}


ISR(TIMER0_OVF_vect)
{
	TCNT0 = 125;
	ticks++;	
    ;
    ;
}
