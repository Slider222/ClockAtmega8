
#ifndef DISPL_H
#define	DISPL_H



#define clockInput       PB1
#define dataInput        PB2
#define dataEnable1      PB3
#define dataEnable2      PB4

#define DIGIT6(data)  (data)%10
#define DIGIT5(data)  (data/10%10)
#define DIGIT4(data)  (data/100)%10
#define DIGIT3(data)  (data/1000)%10
#define DIGIT2(data)  (data/10000)%10
#define DIGIT1(data)  (data/100000)

void port_init();
void SPI_SendByte(uint64_t byte);
void sendNumber(uint32_t digit, uint8_t num);


#endif	/* XC_HEADER_TEMPLATE_H */

