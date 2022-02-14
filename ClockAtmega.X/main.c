#include "funct.h"


volatile uint64_t ticks = 0;
volatile uint32_t curentTime = 0;
uint32_t analogTemp = 0;


int main(void) {
    port_init();
    timerInit();
    analogInit();
    startConversion();
    uint8_t hours = 12, mins = 00, secs = 0;
    sei();
    uint32_t prevtime1 = 0, prevtime2 = 0, prevtime3 = 0, prevtime5 = 0;
    uint8_t buttonTrigName = 0, buttonLongName = 0;
    
    while (1) {       
    curentTime = ticks_ms();
    buttonTrigName = trig_button(); 
    buttonLongName = longTupButton();

    if (buttonLongName == ONE){
       if (ticks_ms() - prevtime2 >= LONGINC){
          hours++;
          prevtime2 = ticks_ms();
        }                
       
    }
    if (buttonTrigName == ONE){
       hours++;
    }

    if (buttonLongName == TWO){
       if (ticks_ms() - prevtime5 >= LONGINC){
          mins++;
          prevtime5 = ticks_ms();
        }                
       
    }
    if (buttonTrigName == TWO){
       mins++;
    }    
    

    
    if (ticks_ms() - prevtime1 >= 1000){
        secs++;        
        prevtime1 = ticks_ms();
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
      
        
    
      if (ticks_ms() - prevtime3 >= 30){
          sendClock(hours, mins, secs);
          prevtime3 = ticks_ms();
    }                  
        
     
     
    }
}


ISR(TIMER0_OVF_vect)
{
	TCNT0 = 5;
	ticks++;    
}

ISR(ADC_vect){
    analogTemp = ADC * TEMPCONST;
}
