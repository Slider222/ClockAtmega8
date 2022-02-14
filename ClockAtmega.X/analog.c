#include "funct.h"

void analogInit(){
    ADMUX |= (1 << REFS0)|(1 << REFS1);
    ADCSRA |= (1 << ADFR)|(1 << ADPS0)|(1 << ADPS1)|(1 << ADPS2)|(1 << ADIE)|(1 << ADEN);
    
}


void startConversion(){
   ADCSRA |= (1 << ADSC);
   
}