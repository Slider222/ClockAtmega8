#include "funct.h"

extern volatile uint32_t curentTime;
volatile uint32_t prevTime3 = 0;
volatile uint32_t prevTime4 = 0;


unsigned char getKey(){
	static unsigned char result = 0;
	static uint8_t count = 0;
	 if (count <= 1){
		PORTB |= (1 << PINB0);
		PORTD &= ~(1 << PIND5); 
	 } else {
		PORTD |= (1 << PIND5);
		PORTB &= ~(1 << PINB0); 
	 }	
	if (curentTime - prevTime4 >= 30){		   
	   if (~PIND & (1 << PIND6)){
		  if (PINB & (1 << PINB0)){
			 result = 3; 
		  } else {
			 result = 4;
		  }	      
	   } else if (~PIND & (1 << PIND7)) {
		 if (PINB & (1 << PINB0)){
			result = 1; 
		 } else {
			result = 2; 
		 }     
	   } else {
		 result = 0;
		 count++;
	   }	    
		 if (count == 4){
			 count = 0;
		 }
		 prevTime4 = curentTime;		 
	   }
	return result;
}


uint8_t trig_button(){
		static uint8_t count = 0;        
		uint8_t key = getKey();
		if (key > 0){
			if (count == 0){
				count = key;                
			} else {
				return 0;
			}			
		} else { 
          count = 0;		  
        }
		return count;	
	 }


uint8_t longTupButton(){
   uint8_t key = getKey();
   static uint8_t count = 0;
   if (key > 0){
      count++; 
   } else {
       count = 0;
   } 
   if (count >= LONGTUP) {
       
   }
    
}