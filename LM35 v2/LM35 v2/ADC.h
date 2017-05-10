/*
 * ADC.h
 *
 * Created: 20/8/2016 
 *  Author: Ali
 */ 


#ifndef ADC_H_
#define ADC_H_
#define ADC0	00000
#define ADC1	00001
#define ADC2	00010
#define ADC3	00011
#define ADC4	00100
#define ADC5	00101
#define ADC6	00110
#define ADC7	00111

#include "StdTypes.h"
void ADC_Init(void);
u16 ADC_read(unsigned char channel);


#endif /* ADC_H_ */