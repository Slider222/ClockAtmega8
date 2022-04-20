#include "funct.h"



volatile uint64_t ticks = 0;
volatile uint32_t curentTime = 0;
uint32_t analogTemp = 0;

uint32_t musicTime = 0;


int main(void) {
    port_init();
    timerInit();
    analogInit();
    startConversion();
    uartInit(MYUBRR);
    uint8_t hours = 12, mins = 00, secs = 00;
    sei();
    uint32_t prevtime1 = 0, prevtime2 = 0, prevtime3 = 0, prevtime4 = 0, prevtime6 = 0, prevtime7 = 0;
    uint8_t buttonTrigName = 0, buttonLongName = 0;
    uint8_t screenTemp = 0;
    uint8_t displeyOff = 0;
    uint32_t averageVal = analogTemp;
    uint32_t valState = 0;
    
    while (1) {       
    curentTime = ticks_ms();
    buttonTrigName = trig_button(); 
    buttonLongName = longTupButton();

    if (buttonLongName == ONE){
       if (ticks_ms() - prevtime2 >= LONGINC){
          hours++;
          prevtime6 = prevtime2 = ticks_ms();
        } 
    }
    if (buttonTrigName == ONE){
       prevtime6 = ticks_ms(); 
       hours++;
    }

    if (buttonLongName == TWO){
       if (ticks_ms() - prevtime4 >= LONGINC){
          mins++;
          prevtime6 = prevtime4 = ticks_ms();
        }                
       
    }
    if (buttonTrigName == TWO){
       prevtime6 = ticks_ms();
       mins++;
    }

    if (buttonTrigName == THREE){
       displeyOff ^= 1;       
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
        if (displeyOff == 0){
            if (screenTemp == 0){
              sendClock(hours, mins, secs);
          } else {
              sendTemp(averageVal);
          }         
        } else {
            offDispley();
        }          
          
          prevtime3 = ticks_ms();
    }                  
    
    if (ticks_ms() - prevtime6 >= 5000){
        screenTemp ^= 1;
        uartTransmit32(127500);        
        prevtime6 = ticks_ms();
    }
    
    valState = analogTemp;
    if (ticks_ms() - prevtime7 >= 1000){
        averageVal = (averageVal * 10 + valState)/11;      
        prevtime7 = ticks_ms();
    }
   
   
    }         //while
}            //main


ISR(TIMER0_OVF_vect){
	TCNT0 = 7;
	ticks++;    
}

ISR(ADC_vect){
    
    analogTemp = ADC * 247;
}
