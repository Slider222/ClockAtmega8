#include "funct.h"


volatile uint32_t prevTime0 = 0;




unsigned char getKey(){
	static unsigned char key = 0;     
	static uint8_t count = 0;
	 if (count <= 1){
		PORTB |= (1 << PINB0);
		PORTD &= ~(1 << PIND5); 
	 } else {
		PORTD |= (1 << PIND5);
		PORTB &= ~(1 << PINB0); 
	 }	
	if (ticks_ms() - prevTime0 >= 30){		   
	   if (~PIND & (1 << PIND6)){
		  if (PINB & (1 << PINB0)){
			 key = THREE; 
		  } else {
			 key = FOUR;
		  }	      
	   } else if (~PIND & (1 << PIND7)) {
		 if (PINB & (1 << PINB0)){
			key = ONE; 
		 } else {
			key = TWO; 
		 }     
	   } else {
		 key = 0;
		 count++;
	   }	    
		 if (count == 4){
			 count = 0;
		 }
		 prevTime0 = ticks_ms();		 
	   } 
    return key;
}








uint8_t trig_button(){
		static uint8_t count = 0;        
		uint8_t key = getKey();
        uint8_t presKey = 0;
		if (key > 0){
			if (count == 0){
                count = 1;
				presKey = key;                
			} else {
				return 0;
			}			
		} else { 
          count = 0;
          presKey = 0;		  
        }
		return presKey;	
	 }


uint8_t longTupButton(){
   static uint16_t count = 0;
   static uint8_t presKey = 0;
   uint8_t key = getKey();   
        if (key > 0){            
            count++;
            if (count == LONGTUP){
                presKey = key;
                count = 0;
            }
        } else {
            count = 0;
            presKey = 0;
        }
   
    return presKey;
    
}