/*
 * ADC.h
 *
 * Created: 17/10/2015 08:58:51 م
 *  Author: hossam
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


void ADC_Init(void);
unsigned char read_adc(unsigned char channel);


#endif /* ADC_H_ */