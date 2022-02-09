#include "funct.h"

void port_init()//weightController
{	
//	DDRB |= (1 << PORTB0)|(1 << SSs)|(1 << SCKk)|(1 << MOSIi);  //??????
//	PORTB |= (1 << dataEnable2);
	
	
	DDRB |= (1 << clockInput)|(1 << dataInput)|(1 << dataEnable1)|(1 << dataEnable2);
	PORTB |= (1 << dataEnable1)|(1 << dataEnable2);
	
	//DDRA |= (1 << PINA4)| (1 << PINA5);          //????? ??????
	//PORTA |=(1 << PINA4);
	
	//DDRA |= (1 << PINA6)| (1 << PINA3);          //????? ??????
    //PORTA |= (1 << PINA6);	
	
}

void SPI_SendByte(uint64_t byte){	   	  
	   PORTB |= (1 << dataInput);
	   PORTB |= (1 << clockInput);
	   PORTB &= ~(1 << clockInput);
	   
	   for (int i = 0; i < 36; i++)
	   {
		   if ((byte & 0x01) == 0x00)
		   {
			   PORTB &= ~(1 << dataInput);
		   }
		   else {PORTB |= (1 << dataInput);}
		   byte = byte >> 1;
		   PORTB |= (1 << clockInput);
		   PORTB &= ~(1 << clockInput);
	   }
	   PORTB |= (1 << dataEnable1);
	   PORTB |= (1 << dataEnable2);	
}



void sendNumber(uint32_t digit, uint8_t num){
		 static volatile uint8_t slovo1 = 0, slovo2 = 0, slovo3 = 0, slovo4 = 0, slovo5 = 0, slovo6 = 0, minus = 0;
		 volatile uint64_t rezult1 = 0, rezult2 = 0;
		 int32_t data = digit;// * 10;
	                                  //0    1      2     3     4     5     6     7     8     9    _
	     volatile uint8_t array[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x00, 0x40};	                          
		 data = labs(data);
         if (data > 100000){
	         data = data / 10;
         }
		 if (digit < 0){
			minus = array[11];  
		 } else {
			minus = array[10]; 
		 }
		 static uint8_t digitTemp1 = 0xff; 
		 static uint8_t digitTemp2 = 0xff;
         static uint8_t digitTemp3 = 0xff;
         static uint8_t digitTemp4 = 0xff;
         static uint8_t digitTemp5 = 0xff;
         static uint8_t digitTemp6 = 0xff;

        
         static uint8_t count = 1;
         
         if ((data >= 100000)  & (data < 1000000)){					   
		     slovo1 = (array[DIGIT1(data)]) & digitTemp1;          
             slovo2 = (array[DIGIT2(data)]) & digitTemp2;            
             slovo3 = (array[DIGIT3(data)]) & digitTemp3;          
             slovo4 = (array[DIGIT4(data)]) & digitTemp4;          
             slovo5 = ((array[DIGIT5(data)])^0x80) & digitTemp5;         
             slovo6 = (array[DIGIT6(data)] & digitTemp6);		     
		 }
		  if (data < 100000 && data >= 10000){				  
             slovo1 = minus;
             slovo2 = (array[DIGIT2(data)]) & digitTemp2;            
             slovo3 = (array[DIGIT3(data)] & digitTemp3);          
             slovo4 = (array[DIGIT4(data)] & digitTemp4);         
             slovo5 = ((array[DIGIT5(data)])^0x80) & digitTemp5;         
             slovo6 = (array[DIGIT6(data)] & digitTemp6);	     
		  }
		  if (data < 10000 && data >= 1000){
			 slovo1 = 0x00;
			 slovo2 = minus;
			 slovo3 = (array[DIGIT3(data)]) & digitTemp3;    
			 slovo4 = (array[DIGIT4(data)]) & digitTemp4;      
			 slovo5 = ((array[DIGIT5(data)])^0x80) & digitTemp5;       
			 slovo6 = (array[DIGIT6(data)] & digitTemp6);		     
      }
		  if (data < 1000 && data >= 100){
			   slovo1 = 0x00;
			   slovo2 = 0x00;
			   slovo3 = minus;
			   slovo4 = (array[DIGIT4(data)]) & digitTemp4;     
			   slovo5 = ((array[DIGIT5(data)])^0x80) & digitTemp5;     
               slovo6 =(array[DIGIT6(data)] & digitTemp6);		     
		  }
		 if (data < 100 && data >= 10){
			 slovo1 = 0x00;
			 slovo2 = 0x00;
			 slovo3 = 0x00;
             slovo4	= minus;
			 slovo5 = ((array[DIGIT5(data)])^0x80) & digitTemp5;      
             slovo6 = (array[DIGIT6(data)] & digitTemp6);		     
		 }
		   if (data < 10 && data >= 0){
			   slovo1 = 10;
			   slovo2 = 10;
			   slovo3 = 10;
			   slovo4 = 10;
			   slovo5 = minus; 
               slovo6 = (array[DIGIT6(data)] & digitTemp6);		         
		   }

//         if (blinkOnTimer(500) == 1) {
//	         if (count == 0){
//                 switch (num){
//                    case 1:
//                     digitTemp6 = 0x00;                    
//                     count = 1;
//                     break;
//                    case 2:
//                     digitTemp5 = 0x00;                     
//                     count = 1;
//                     break;
//                    case 3:
//                     digitTemp4 = 0x00;                     
//                     count = 1;
//                     break;
//                    case 4:
//                     digitTemp3 = 0x00;                     
//                     count = 1;
//                     break;
//                    case 5:
//                     digitTemp2 = 0x00;                     
//                     count = 1;
//                     break;
//                 } 
//		         
//		     } else {
//		         digitTemp2 = digitTemp3 = digitTemp4 = digitTemp5 = digitTemp6 = 0xff;		        
//		         count = 0;
//	         }	         
//         }


		 rezult1 = (((rezult1 |slovo6)<<16)&0xff0000)|(((rezult1 |slovo5)<<8)&0xff00)|((rezult1 | slovo4)&0xff);
		 rezult2 = (((rezult2 |slovo3)<<16)&0xff0000)|(((rezult2 | slovo2)<<8)&0xff00)|((rezult2 | slovo1)&0xff);
		 PORTB &= ~(1 << dataEnable2);
		 SPI_SendByte( rezult1);
		 PORTB &= ~(1 << dataEnable1);
		 SPI_SendByte( rezult2);
	 }