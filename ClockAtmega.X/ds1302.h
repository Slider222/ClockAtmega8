
#ifndef DS1302_H
#define	DS1302_H


void RTC_SendByte(uint8_t byte);
uint8_t RTC_ReadByte();
uint8_t RTC_ReadReg(uint8_t adresse);



#endif	/* DS1302_H */

