 
#ifndef FUNCT_H
#define	FUNCT_H

#include <avr/io.h>
#include "button.h"
#include "disp.h"
#include <stdlib.h>
#include <util/atomic.h>
#include <avr/interrupt.h>
#include "analog.h"
#include "uart.h"
#include "buzzer.h"
#include <avr/pgmspace.h>



void timerInit();
uint64_t ticks_ms();

#endif	/* FUNCT_H */

