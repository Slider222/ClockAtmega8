#include "funct.h"

extern uint32_t musicTime;
uint16_t durations;
uint8_t countMassive;
uint16_t countNote;


void playMuisic(const uint16_t* notes, const uint16_t* beats, uint8_t size){
		if (ticks_ms() - musicTime >= durations){
			if (countMassive == 1){
				DDRB &= ~(1 << PORTB3);
				countMassive = 0;
				durations = durations / 3;
			}
			else {
				TCCR2 |=(1 << CS02);
				OCR2 = 28800/pgm_read_word(&notes[countNote]);
				DDRB |= (1 << PORTB4);
				durations =  pgm_read_word(&(beats[countNote]))*1.2; // 3*/;
				countMassive = 1;
				countNote++;
			}
			if (countNote >= size){						         //39
				countNote = 0;
			}
		 
			musicTime = ticks_ms();
		}
	
}


