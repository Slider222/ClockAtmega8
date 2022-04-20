
#ifndef DS1302_H
#define	DS1302_H


void RTC_SendByte(uint8_t byte);
uint8_t RTC_ReadByte();
void RTC_ReadClock();
void RTC_SetHour(uint8_t hours);
void RTC_SetMin(uint8_t mins);
void RTC_Unlock();


#endif	/* DS1302_H */

