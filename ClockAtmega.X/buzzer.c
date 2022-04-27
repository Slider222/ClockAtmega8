#include "funct.h"


extern uint32_t musicTime;
uint16_t durations;
uint8_t countMassive;
uint16_t countNote;
extern uint8_t lev_ch1;



void playMuisic(const uint16_t* notes, const uint16_t* beats, uint8_t size){
		if (ticks_ms() - musicTime >= durations){
			if (countMassive == 1){
				DDRB &= ~(1 << PWM_OUT);
				countMassive = 0;
				durations = durations / 3;
			}
			else {
				TCCR2 |=(1 << CS21)|(1 << CS22);
				OCR2 = 31256/pgm_read_word(&notes[countNote]); //28800  1600000/(256*2)/notes
				DDRB |= (1 << PWM_OUT);
				durations =  pgm_read_word(&(beats[countNote]))*1; // 3*/;
				countMassive = 1;
				countNote++;
			}
			if (countNote >= size){						         //39
				countNote = 0;
			}
		 
			musicTime = ticks_ms();
		}
	
}


void stopMuisic(){
    DDRB &= ~(1 << PWM_OUT);
    TCCR2 &=~((1 << CS21)|(1 << CS22));
}

const uint16_t note4[] PROGMEM ={
	293, 493, 493, 440, 493,
	392, 293, 293, 293,
	493, 493, 523, 659,
	587,           587,
	329, 329, 523, 523,
	493, 440, 392, 293,
	493, 493, 440, 493,
	392,           392,
	329, 329, 523, 523,
	493, 440, 392, 293,
	493, 493, 440, 493,
392};


const uint16_t beat4[] PROGMEM =			 {
	250, 250, 250, 250, 250,
	250, 250, 250, 250,
	250, 250, 250, 250,
	500,           250,
	250, 250, 250, 250,
	250, 250, 250, 250,
	250, 250, 250, 250,
	500,           250,
	250, 250, 250, 250,
	250, 250, 250, 250,
	250, 250, 250, 250,
500};



const uint16_t note[] PROGMEM =     {
	392, 392, 392, 311, 466, 392, 311, 466, 392,			              //????????? ???? *3/2 //39
	587, 587, 587, 622, 466, 369, 311, 466, 392,
	784, 392, 392, 784, 739, 698, 659, 622, 659,
	415, 554, 523, 493, 466, 440, 466,
    311, 369, 311, 466, 392 };
const uint16_t beat[] PROGMEM ={
	350, 350, 350, 250, 100, 350, 250, 100, 700,
	350, 350, 350, 250, 100, 350, 250, 100, 700,
	350, 250, 100, 350, 250, 100, 100, 100, 450,
	150, 350, 250, 100, 100, 100, 450,
    150, 350, 250, 100, 750 };




