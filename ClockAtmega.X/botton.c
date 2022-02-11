#include "funct.h"

extern volatile uint32_t curentTime;
volatile uint32_t prevTime3 = 0;
volatile uint32_t prevTime4 = 0;
volatile unsigned char pressedKey = 0;
unsigned int comp = 0;


void buttonIn(){
	unsigned char key; 
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
		 prevTime4 = curentTime;		 
	   }
    
    
	 if (key){
	   if (comp > 7000) {
		   comp = 3000;
		   pressedKey = key + LONGTUP; 		  
		   return;
	   }
	   else comp++;
       
	   if (comp == 10)
	   {
		   pressedKey = key;
		   return;
	   } 	   
   }
   else{ 
	   comp = 0;	   
   }  
}

unsigned char BUT_GetKey(void)
{
	unsigned char key = pressedKey;	
	pressedKey = 0;
	return key;
}






//uint8_t trig_button(){
//		static uint8_t count = 0;        
//		uint8_t key = getKey();
//		if (key > 0){
//			if (count == 0){
//				count = key;                
//			} else {
//				return 0;
//			}			
//		} else { 
//          count = 0;		  
//        }
//		return count;	
//	 }


//uint8_t longTupButton(){
//   uint8_t key = getKey();
//   static uint8_t count = 0;
//   if (key > 0){
//      count++; 
//   } else {
//       count = 0;
//   } 
//   if (count >= LONGTUP) {
//       ;
//   }
//    
//}