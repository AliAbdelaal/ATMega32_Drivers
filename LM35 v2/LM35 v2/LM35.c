/*
 * LM35.c
 *
 * Created: 20-Aug-16 3:27:36 AM
 *  Author: Ali
 */ 
#include "LM35.h"
#include "ADC.h"
/************************************************************************/
	/* as the lm35 changes 10mv per 1 celisus , the step will be calculated
		using the resolution (10bit >> 1023 step ) and with the aid of Vref 
		we calculate the volt/step (10bit and 5v ref >> gives us 4.88v/step)
		then divide the 10mv by the step volt , will give us the number 
		that we divide the adcRead with                                      */
	/************************************************************************/

static u8 adcPin = 0x00 ;
static float magicNumber = 0 ;

void	LM35_init(u8 ADCpin , float referenceVoltage , u16 adcResolution)
{
	ADC_Init();
	adcPin = ADCpin ; 
	//calculate the magicNumber 
	magicNumber = 10/((referenceVoltage/adcResolution)*1000) ;
}
float	LM35_floatRead() 
{
	u16 adcRead ;
	float temp  ; 
	adcRead = ADC_read(adcPin) ;
	temp = adcRead / magicNumber ;
	return temp ;
}
u8		LM35_u8Read() 
{
	u8 temp ;
	u16 adcRead ; 
	adcRead = ADC_read(adcPin) ;
	temp = (u8) adcRead / magicNumber ;
	return temp ;
}