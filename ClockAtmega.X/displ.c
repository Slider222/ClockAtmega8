#include "funct.h"
                          //0    1      2     3     4     5     6     7     8     9    _    _min    _C
const uint8_t array[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x00, 0x40, 0x39};	
uint8_t displeyBuffer[6];
 uint8_t displeyBuffer[6];
 
 uint8_t _delayEffect = 100;
 uint8_t _effectMode = 1;
 uint8_t _processIsBusy = 0;
 
 uint32_t prevTime1  = 0;
 uint32_t prevTime3 = 0;
 
 uint8_t _hour;
 uint8_t _min;
 uint8_t _sec;


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
	sendLeft();	
	sendRight();
}

void setClock(uint8_t hour, uint8_t min, uint8_t sec){
	_hour = hour;
	_min = 	min;
	_sec = sec;
}

void setClockToBuffer(){
         static uint8_t slovo[6];                          
		 slovo[0] = array[DIVIDE10(_hour)];
         slovo[1] = (array[MOD10(_hour)]) ^0x80;
    
         slovo[2] = array[_min / div10];
         slovo[3] = (array[_min % div10]) ^0x80;
    
         slovo[4] = array[_sec / div10];
         slovo[5] = (array[_sec % div10]);
         
         for (uint8_t i = 0; i < 6; i ++){
             displeyBuffer[i] = slovo[i];
         }
         
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
    
    
    
   
}

uint8_t getPixel(uint8_t x, uint8_t* buffer){
	if (x < 8){		
		return (buffer[0] & (1 << x)) ? 1 : 0;				
	} else if (x >= 8 && x < 16 ) {
		return (buffer[1] & (1 << (x - 8))) ? 1 : 0;
	} else if (x >= 16 && x < 24 ) {
	   return (buffer[2] & (1 << (x - 16))) ? 1 : 0;
	} else if ((x >= 24) && (x < 32)) {
		return (buffer[3] & (1 << (x - 24))) ? 1 : 0;
    } else if (x >= 32 && x < 40 ) {										   //(~GPIO & (1 << 4)){
        return (buffer[4] & (1 << (x - 32))) ? 1 : 0;
    } else if (x >= 40 && x < 48 ) {
        return (buffer[5] & (1 << (x - 40))) ? 1 : 0;
    } else {
		return 0x00;
	}
}

void drawPixel(uint8_t x){
	if (x < 8){
		displeyBuffer[0] |= (1 << x);
		} else if (x >= 8 && x < 16 ) {
		displeyBuffer[1] |= (1 << (x - 8));
		} else if (x >= 16 && x < 24 ) {
		displeyBuffer[2] |= (1 << (x - 16));
		} else if (x >= 24 && x < 32 ) {
		displeyBuffer[3] |= (1 << (x - 24));
		} else if (x >= 32 && x < 40 ) {
		displeyBuffer[4] |= (1 << (x - 32));
		} else if (x >= 40 && x < 48 ) {
		displeyBuffer[5] |= (1 << (x - 40));
		} 
}

void sendClockWithEffect(){
	static uint8_t i, j = 0;
	static uint8_t tempBuff[6];	
	if (i == 0){
		for (uint8_t k = 0; k < 6; k++){
			tempBuff[k] = displeyBuffer[k];
		}
		clearDispl();
		i = 1;
		_processIsBusy = 1;
	}
		
	  if (getPixel(j, tempBuff)){
		_delayEffect = 100;
		 drawPixel(j); 
	  } else {_delayEffect = 0;}
	 
		
		
	if (ticks() - prevTime1 >= _delayEffect){		
		if (j++ >= 48){
			j = 0;
			i = 0;			
			_processIsBusy = 0;
		}
		prevTime1 = ticks();
	}
}

void processEffect(uint8_t aMode){
	switch (aMode) {
		case 1: sendClockWithEffect(); break;
		case 2: setClockToBuffer();	break;
 }
}


void doEffectWithOverlay(uint8_t aMode){	
	 processEffect(aMode);
}

void offDispley(){
    PORTB &= ~(1 << dataEnable2);
    
    PORTB &= ~(1 << dataEnable1);
    
}





