/*
 * adc.c
 *
 * Created: 17/10/2015 08:56:31 م
 *  Author: hossam
 */ 
#include <avr/io.h>
#include "StdTypes.h"
void ADC_Init(void)
{
	/*VREF=AREF and 8 bits precision */
	/*left adjust result */
	ADMUX |= 1 << ADLAR ; 
	/*enable ADC, single conversion,500 khz sampling frequency*/
	ADCSRA |= 1 <<ADEN ;	//enable ADC
	ADCSRA |= 1 <<ADPS2 ;	//16 prescale
	
}

unsigned char read_adc(unsigned char channel)
{
	/*select channel*/
	ADMUX |= channel<<MUX0 ;
	
/*start conversion*/
	ADCSRA |= 1<<ADSC ;
	
	/*wait until conversion end*/
	while((ADCSRA& 1 << ADIF) == 0) ;
	
	/*clear the flag*/
	ADCSRA |= 1<<ADIF ; 
	
	/*Read the Result*/
	u8 result = ADCH ;
	return result ;
}