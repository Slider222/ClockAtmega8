
#ifndef DISPL_H
#define	DISPL_H





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



void offDispley();
void sendTemp(uint32_t temp);
void setPort();
void sendLeft();
void sendRight();
void update();
void setClockToBuffer();
void clearDispl();

void processEffect(uint8_t aMode);
void sendClockWithEffect();
void doEffectWithOverlay(uint8_t aMode);
void setClock(uint8_t hour, uint8_t min, uint8_t sec);
uint8_t getPixel(uint8_t x, uint8_t* buffer);
void drawPixel(uint8_t x);
void customRoutine(uint8_t aMode);
#endif	/* XC_HEADER_TEMPLATE_H */

