 
#ifndef FUNCT_H
#define	FUNCT_H

#define F_CPU 16000000UL

#define clockInput       PB1
#define dataInput        PB2
#define dataEnable1      PB3
#define dataEnable2      PB4
#define PWM_OUT          PB5

#define RTC_CLK          PD2  //D2
#define RTC_DAT          PD3  //D3
#define RTC_CE           PD4  //D4



//PB0 - button
//PD5 - button
//PD6 - button
//PD7 - button

#include <avr/io.h>
#include "button.h"
#include "disp.h"
#include <stdlib.h>
#include <util/atomic.h>
#include <avr/interrupt.h>
#include "analog.h"
#include "uart.h"
#include "buzzer.h"
#include "ds1302.h"
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/eeprom.h>







void port_init();
void timerInit();
uint64_t ticks_ms();
uint8_t hexToBin(uint8_t data);
uint8_t binToHex(uint8_t data);

#endif	/* FUNCT_H */

