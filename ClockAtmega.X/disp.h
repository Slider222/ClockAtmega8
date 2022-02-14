
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

#define DIVIDE10(x)(x/10)
#define MOD10(x)(x%10)

#define shift16 16
#define shift8   8
#define div10   10


void port_init();
void SPI_SendByte(uint32_t byte);
void sendClock(uint8_t hour, uint8_t min, uint8_t sec);
void sendTemp(uint16_t temp);

#endif	/* XC_HEADER_TEMPLATE_H */

