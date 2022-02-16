#include "funct.h"
                                  //0    1      2     3     4     5     6     7     8     9    _    _min    _C
	     const uint8_t array[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x00, 0x40, 0x39};	


void port_init()//weightController
{	
	DDRB |= (1 << PORTB0);    //?????? ??? ??????
    DDRD |= (1 << PORTD5);

	
	
	DDRB |= (1 << clockInput)|(1 << dataInput)|(1 << dataEnable1)|(1 << dataEnable2);
	PORTB |= (1 << dataEnable1)|(1 << dataEnable2);
	
	//DDRA |= (1 << PINA4)| (1 << PINA5);          //????? ??????
	//PORTA |=(1 << PINA4);
	
	//DDRA |= (1 << PINA6)| (1 << PINA3);          //????? ??????
    //PORTA |= (1 << PINA6);	
	
}

void SPI_SendByte(uint32_t byte){	   	  
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



void sendClock(uint8_t hour, uint8_t min, uint8_t sec){
		 static uint8_t slovo1 = 0, slovo2 = 0, slovo3 = 0, slovo4 = 0, slovo5 = 0, slovo6 = 0;
		 uint32_t rezult1 = 0, rezult2 = 0;
		 
	                                                        
		 slovo1 = array[DIVIDE10(hour)];
         slovo2 = (array[MOD10(hour)]) ^0x80;
    
         slovo3 = array[min / div10];
         slovo4 = (array[min % div10]) ^0x80;
    
         slovo5 = array[sec / div10];
         slovo6 = (array[sec % div10]); 
         
		 rezult1 = (((rezult1 |slovo6)<<16)&0xff0000)|(((rezult1 |slovo5)<<8)&0xff00)|((rezult1 | slovo4)&0xff);
		 rezult2 = (((rezult2 |slovo3)<<16)&0xff0000)|(((rezult2 | slovo2)<<8)&0xff00)|((rezult2 | slovo1)&0xff);
		 PORTB &= ~(1 << dataEnable2);
		 SPI_SendByte( rezult1);
		 PORTB &= ~(1 << dataEnable1);
		 SPI_SendByte( rezult2);
         ;
	 }



void sendTemp(uint32_t temp){
    uint16_t data = temp/100;
    uint8_t slovo1 = 0, slovo2 = 0, slovo3 = 0;
    uint32_t rezult1 = 0, rezult2 = 0;
    slovo1 = array[data/100];
    slovo2 = (array[(data/10)%10]) ^0x80;
    slovo3 = array[(data%10)];
    
    
    
    rezult1 = (((rezult1 | array[12])<<16)&0xff0000)|(((rezult1 |0x63)<<8)&0xff00)|((rezult1 |0x00 )&0xff);        
    rezult2 = (((rezult2 |slovo3)<<16)&0xff0000)|(((rezult2 | slovo2)<<8)&0xff00)|((rezult2 | slovo1)&0xff);  
    
    PORTB &= ~(1 << dataEnable2);
    SPI_SendByte( rezult1);
    PORTB &= ~(1 << dataEnable1);
    SPI_SendByte( rezult2);
}

void offDispley(){
    PORTB &= ~(1 << dataEnable2);
    SPI_SendByte(0);
    PORTB &= ~(1 << dataEnable1);
    SPI_SendByte(0);
}





