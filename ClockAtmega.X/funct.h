 
#ifndef FUNCT_H
#define	FUNCT_H


#define clockInput       PB1
#define dataInput        PB2
#define dataEnable1      PB3
#define dataEnable2      PB4

#define RTC_CLK       PC0  //A0
#define RTC_DAT        PC1  //A1
#define RTC_CE         PC2  //A2



//PB0 - ??????
//PD5 - ??????
//PD6 - ??????
//PD7 - ??????

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

