 
#ifndef FUNCT_H
#define	FUNCT_H


#define clockInput       PB1
#define dataInput        PB2
#define dataEnable1      PB3
#define dataEnable2      PB4
#define LEDPIN           PB5

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







void port_init();
void timerInit();
uint64_t ticks_ms();

#endif	/* FUNCT_H */

