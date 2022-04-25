#include "funct.h"
                          //0    1      2     3     4     5     6     7     8     9    _    _min    _C
const uint8_t array[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x00, 0x40, 0x39};	
uint8_t displeyBuffer[6];


void clearDispl(){
	for (uint8_t i = 0; i < 6; i++){
		displeyBuffer[i] = 0x00;
	}
}


void sendLeft(){
	PORTB &= ~(1 << dataEnable1);
	PORTB |= (1 << dataInput);
	PORTB |= (1 << clockInput);
	PORTB &= ~(1 << clockInput);
	
	for (uint8_t i = 0; i < 3; i++){
		uint8_t byte = displeyBuffer[i];
		for (uint8_t j = 0; j < 8; j++){
			if ((byte & 0x01) == 0x00){
				PORTB &= ~(1 << dataInput);
				} else {
				PORTB |= (1 << dataInput);
			}
			byte = byte >> 1;
			PORTB |= (1 << clockInput);
			PORTB &= ~(1 << clockInput);
		}
	}
	for (uint8_t i = 0; i < 12; i++){
		PORTB &= ~(1 << dataInput);
		PORTB |= (1 << clockInput);
		PORTB &= ~(1 << clockInput);
	}
	
	PORTB |= ~(1 << dataEnable2);
	PORTB |= (1 << dataEnable1);
	
}


void sendRight(){
	PORTB &= ~(1 << dataEnable2);
	PORTB |= (1 << dataInput);
	PORTB |= (1 << clockInput);
	PORTB &= ~(1 << clockInput);
	
	for (uint8_t i = 3; i < 6; i++){
		uint8_t byte = displeyBuffer[i];
		for (uint8_t j = 0; j < 8; j++){
			if ((byte & 0x01) == 0x00){
				PORTB &= ~(1 << dataInput);
				} else {
				PORTB |= (1 << dataInput);
			}
			byte = byte >> 1;
			PORTB |= (1 << clockInput);
			PORTB &= ~(1 << clockInput);
		}
	}
	for (uint8_t i = 0; i < 12; i++){
		PORTB &= ~(1 << dataInput);
		PORTB |= (1 << clockInput);
		PORTB &= ~(1 << clockInput);
	}
	
	PORTB |= ~(1 << dataEnable2);
	PORTB |= (1 << dataEnable1);
	
}

void update(){	
	sendLeft(displeyBuffer);
	sendRight(displeyBuffer);
}


void sendClock(uint8_t hour, uint8_t min, uint8_t sec){
         static uint8_t slovo[6];                          
		 slovo[0] = array[DIVIDE10(hour)];
         slovo[1] = (array[MOD10(hour)]) ^0x80;
    
         slovo[2] = array[min / div10];
         slovo[3] = (array[min % div10]) ^0x80;
    
         slovo[4] = array[sec / div10];
         slovo[5] = (array[sec % div10]);
         
         for (uint8_t i = 0; i < 6; i ++){
             displeyBuffer[i] = slovo[i];
         }
         //memcpy(&displeyBuffer, &slovo, 6);
        
          
         
//		 rezult1 = (((rezult1 |slovo6)<<16)&0xff0000)|(((rezult1 |slovo5)<<8)&0xff00)|((rezult1 | slovo4)&0xff);
//		 rezult2 = (((rezult2 |slovo3)<<16)&0xff0000)|(((rezult2 | slovo2)<<8)&0xff00)|((rezult2 | slovo1)&0xff);
//		 PORTB &= ~(1 << dataEnable2);
//		 SPI_SendByte(displeyBuffer);
//		 PORTB &= ~(1 << dataEnable1);
//		 SPI_SendByte( rezult2);
         ;
	 }



void sendTemp(uint32_t temp){
    uint16_t data = temp/100;    
    uint8_t slovo[6];   
    slovo[0] = array[data/100];
    slovo[1] = (array[(data/10)%10]) ^0x80;
    slovo[2] = array[(data%10)];
    
    slovo[3] = 0x00;
    slovo[4] = 0x63;
    slovo[5] = array[12];       
    
    for (uint8_t i = 0; i < 6; i++){
        displeyBuffer[i] = slovo[i];
    }
    
    
    
    //rezult1 = (((rezult1 | array[12])<<16)&0xff0000)|(((rezult1 |0x63)<<8)&0xff00)|((rezult1 |0x00 )&0xff);        
    //rezult2 = (((rezult2 |slovo3)<<16)&0xff0000)|(((rezult2 | slovo2)<<8)&0xff00)|((rezult2 | slovo1)&0xff);  
    
//    PORTB &= ~(1 << dataEnable2);
//    SPI_SendByte( rezult1);
//    PORTB &= ~(1 << dataEnable1);
//    SPI_SendByte( rezult2);
}

void offDispley(){
    PORTB &= ~(1 << dataEnable2);
    
    PORTB &= ~(1 << dataEnable1);
    
}





