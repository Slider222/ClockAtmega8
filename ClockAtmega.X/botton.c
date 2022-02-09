#include "funct.h"




//uint8_t getKey(){
//	static unsigned char result = 0;
//	static uint8_t count = 0;
//	 if (count <= 1){
//		PORTA |= (1 << PINA6);
//		PORTA &= ~(1 << PINA3); 
//	 } else {
//		PORTA |= (1 << PINA3);
//		PORTA &= ~(1 << PINA6); 
//	 }	
//	if (curentTime - prevTime4 >= 30){		   
//	   if (~PINA & (1 << PINA4)){
//		  if (PINA & (1 << PINA6)){
//			 result = 3; 
//		  } else {
//			 result = 4;
//		  }	      
//	   } else if (~PINA & (1 << PINA5)) {
//		 if (PINA & (1 << PINA6)){
//			result = 1; 
//		 } else {
//			result = 2; 
//		 }     
//	   } else {
//		 result = 0;
//		 count++;
//	   }	    
//		 if (count == 4){
//			 count = 0;
//		 }
//		 prevTime4 = curentTime;		 
//	   }
//	return result;
//}
