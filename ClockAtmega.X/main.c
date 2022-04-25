#include "funct.h"


extern uint8_t bytes[];
extern uint16_t note4[];
extern uint16_t beat4[];
extern uint16_t note[];
extern uint16_t beat[];

extern uint8_t displeyBuffer[6];

volatile uint64_t ticks = 0;
volatile uint32_t curentTime = 0;
uint32_t analogTemp = 0;
uint8_t counter = 0;
uint8_t buf_lev_ch1 = 0;
uint8_t lev_ch1 = 0;




uint32_t musicTime = 0;


int main(void) {
    port_init();
    timerInit();
    analogInit();
    startConversion();
    uartInit(MYUBRR);   
    
    sei();
    uint32_t prevtime1 = 0, prevtime2 = 0, prevtime3 = 0, prevtime4 = 0, prevtime6 = 0, prevtime7 = 0, prevtime8 = 0, prevtime9 = 0;
    uint32_t prevtime10 = 0, prevtime11 = 0, prevtime12 = 0;
    uint8_t buttonTrigName = 0, buttonLongName = 0;
    uint8_t screenTemp = 0;
    uint8_t displeyOff = 0;
    uint8_t writeDataRTC = 0;
    uint8_t writeDataEEPROM = 0;
    uint32_t averageVal = analogTemp;
    uint32_t valState = 0;
    
    uint8_t DS1302_sec = 0;
    uint8_t DS1302_min = 0;
    uint8_t DS1302_hour = 0;
    
    uint8_t DS1302_day = 0;
    uint8_t DS1302_mounth = 0;
    uint8_t DS1302_weekDay = 0;
    uint8_t DS1302_year = 0;
    
    ////////////////////////////////////////////////////read alarm from eeprom
    uint8_t alarmHour = eeprom_read_byte((uint8_t*)0);
    uint8_t alarmMin = eeprom_read_byte((uint8_t*)1);
    uint8_t musicPlay = 0;
    if (alarmHour > 24){
        alarmHour = 0;
    } 
    if (alarmMin > 60){
        alarmMin = 0;
    }     
    
    while (1) {       
    curentTime = ticks_ms();
    buttonTrigName = trig_button(); 
    buttonLongName = longTupButton();
    ////////////////////////////////////////////////////////////////////set data
      
      if (buttonLongName == ONE){
       if (ticks_ms() - prevtime2 >= LONGINC){
          if(screenTemp == 0){
            DS1302_hour++;
            writeDataRTC = 1;
          } else if (screenTemp == 1){
            DS1302_day++;
            writeDataRTC = 2;
          } else if (screenTemp == 3){
              alarmHour++;
              writeDataEEPROM = 1;
          }          
          prevtime8 = prevtime6 = prevtime2 = ticks_ms();
        }       
    }
    
    if (buttonTrigName == ONE){
       prevtime8 = prevtime6 = ticks_ms();
       if(screenTemp == 0){
         DS1302_hour++;
         writeDataRTC = 1;
       } else if (screenTemp == 1){
         DS1302_day++;
         writeDataRTC = 2;
       } else if (screenTemp == 3){
              alarmHour++;
              writeDataEEPROM = 1;
          }                
       
    }

    if (buttonLongName == TWO){
       if (ticks_ms() - prevtime4 >= LONGINC){
          if(screenTemp == 0){
             DS1302_min++;
             writeDataRTC = 1;
          } else if (screenTemp == 1){
             DS1302_mounth++;
             writeDataRTC = 2;
          } else if (screenTemp == 3){
              alarmMin++;
              writeDataEEPROM = 2;
          }                         
          prevtime8 = prevtime6 = prevtime4 = ticks_ms();
        }                
       
    }
    
    if (buttonTrigName == TWO){
       prevtime8 = prevtime6 = ticks_ms();
       if(screenTemp == 0){
          DS1302_min++;
          writeDataRTC = 1;
       } else if (screenTemp == 1){
          DS1302_mounth++;
          writeDataRTC = 2;
       } else if (screenTemp == 3){
              alarmMin++;
              writeDataEEPROM = 2;
        }                                
       
    }  
    
    
    if (buttonLongName == THREE){
       if (ticks_ms() - prevtime9 >= LONGINC){
          if(screenTemp == 1){
             DS1302_year++;
             writeDataRTC = 2;
          } 
          prevtime8 = prevtime6 = prevtime9 = ticks_ms();
        }
    }    

    if (buttonTrigName == THREE){
       prevtime8 = prevtime6 = ticks_ms(); 
       if(screenTemp == 0){
         displeyOff ^= 1;   
       } else if (screenTemp == 1){
         DS1302_year++;
         writeDataRTC = 2;
       }       
    }
    
    if (buttonLongName == FOUR){
        
        screenTemp = 3;
        prevtime6 = ticks_ms();
    }
    
    if (buttonTrigName == FOUR){
        if (musicPlay == 1){
            musicPlay = 0;
        }        
    }
    

    ////////////////////////////////////////////////////////////////READ time from RTC module
    if ((ticks_ms() - prevtime1 >= 500)){
        RTC_ReadClock();
        if (writeDataRTC == 0){
            DS1302_min = hexToBin(bytes[1]);
            DS1302_hour = hexToBin(bytes[2]);
            DS1302_day = hexToBin(bytes[3]);
            DS1302_mounth = hexToBin(bytes[4]);
            DS1302_weekDay = hexToBin(bytes[5]);
            DS1302_year = hexToBin(bytes[6]);
        }         
        DS1302_sec = hexToBin(bytes[0]);        
        prevtime1 = ticks_ms();        	
    }        
        
    
       
      
          
      ///////////////////////////////////////////////////////////////switch screen
      if (ticks_ms() - prevtime3 >= 30){
        if (displeyOff == 0){
            if (screenTemp == 0){                             
              sendClock(DS1302_hour, DS1302_min, DS1302_sec);
          } else if (screenTemp == 1) {              
              sendClock(DS1302_day, DS1302_mounth, DS1302_year);
          } else if (screenTemp == 2){
              sendTemp(averageVal);              
          } 
            else if (screenTemp == 3){
              sendClock(alarmHour, alarmMin, 0x00);              
          }        
        } else {
            offDispley();
        }          
          
          prevtime3 = ticks_ms();
    }                  
    
    if (ticks_ms() - prevtime6 >= 5000){
        screenTemp++;
        if (screenTemp >= 3){
            screenTemp = 0;
        }
        uartTransmit32(127500);        
        prevtime6 = ticks_ms();
    }
    
    
    /////////////////////////////////////////////////////////////write clock into RTC
    
    if (writeDataRTC == 1){
        if (DS1302_min == 60){
           DS1302_min = 0;
           DS1302_hour = DS1302_hour + 1;
       }
        
       if (DS1302_hour == 24){
           DS1302_hour = 0;
       }    
       
        
        if (ticks_ms() - prevtime8 >= 10000){            
            RTC_Unlock();
            RTC_SetHour(binToHex(DS1302_hour));
            RTC_SetMin(binToHex(DS1302_min));
            writeDataRTC = 0;
            prevtime8 = ticks_ms(); 
        }
        
    } else if (writeDataRTC == 2){
        if (DS1302_day >= 32){
           DS1302_day = 1;           
       }
       
       if (DS1302_mounth >= 13){
           DS1302_mounth = 1;           
       }
        
       if (DS1302_year >= 100){
           DS1302_year = 00;           
       }
       if (ticks_ms() - prevtime8 >= 10000){
          RTC_Unlock(); 
          RTC_SetDay(binToHex(DS1302_day));
          RTC_SetMounth(binToHex(DS1302_mounth));
          RTC_SetYear(binToHex(DS1302_year));
          writeDataRTC = 0;
          prevtime8 = ticks_ms(); 
       } 
        
        
    }
    
    
    
    valState = analogTemp;
    if (ticks_ms() - prevtime7 >= 1000){
        averageVal = (averageVal * 10 + valState)/11;      
        prevtime7 = ticks_ms();
    }
    /////////////////////////////////////////delay before pusk
    if (ticks_ms() - prevtime10 >= 1000){
       if ((DS1302_hour == alarmHour) & (DS1302_min == alarmMin) & (DS1302_sec == 1)){
           musicPlay = 1;
        } 
    }
    
    if (ticks_ms() - prevtime12 >= 120000){
        musicPlay = 0;
    }
    
    if (musicPlay == 1){
       playMuisic(note, beat, 39);       
    } else {
       stopMuisic(); 
    }
    
    if (writeDataEEPROM == 1){
        if (alarmHour >= 24){
            alarmHour = 0;
        }
        if (ticks_ms() - prevtime11 >= 10000){
           eeprom_write_byte((uint8_t*)0, alarmHour);
           writeDataEEPROM = 0;
           prevtime11 = ticks_ms(); 
        }
    } else if (writeDataEEPROM == 2) {
        if (alarmMin >= 60){
            alarmMin = 0;
        }
        if (ticks_ms() - prevtime11 >= 10000){
           eeprom_write_byte((uint8_t*)1, alarmMin);
           writeDataEEPROM = 0;
           prevtime11 = ticks_ms(); 
        }
    }
    
    
    
    SPI_SendByte(displeyBuffer);
    }         //while
}            //main

//16000000/256*256 = 244 Hz
ISR(TIMER0_OVF_vect){
	TCNT0 = 7;
	ticks++;
    
}


//////////////////////////////////////     62500/ocr2 = 262 * 2 Hz   
ISR(TIMER2_COMP_vect){
   PORTB ^= (1 << PWM_OUT);
}

ISR(ADC_vect){    
    analogTemp = ADC * 247;
}
