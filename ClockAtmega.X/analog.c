#include "funct.h"

void analogInit(){
    ADMUX |= (1 << REFS0)|(1 << REFS1);
    
}