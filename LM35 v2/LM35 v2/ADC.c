/*
 * ADC.c
 *
 * Created: 20/8/2016  
 *  Author: Ali
 */ 
#include <avr/io.h>
#include "StdTypes.h"
void ADC_Init(void)
{
	/*VREF=AREF and 10 bits precision */
	/*right adjust result */
	ADMUX |= 0 << ADLAR ; 
	/*enable ADC, single conversion,500 khz sampling frequency*/
	ADCSRA |= 1 <<ADEN ;	//enable ADC
	ADCSRA |= 1 <<ADPS2 ;	//16 prescale
	
}

u16 ADC_read(unsigned char channel)
{
	u16 result = 0x00 ;
	/*select channel*/
	ADMUX |= channel<<MUX0 ;
	
/*start conversion*/
	ADCSRA |= 1<<ADSC ;
	
	/*wait until conversion end*/
	while((ADCSRA& 1 << ADIF) == 0) ;
	
	/*clear the flag*/
	ADCSRA |= 1<<ADIF ; 
	
	/*Read the Result*/
	result = ADCL ;
	result |= (ADCH<<8) ;
	return result ;
}