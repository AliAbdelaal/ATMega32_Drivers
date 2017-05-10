/*
 * LM35.h
 *
 * Created: 20-Aug-16 3:25:22 AM
 *  Author: Ali
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "StdTypes.h"

void	LM35_init(u8 ADCpin , float referenceVoltage , u16 adcResolution);
float	LM35_floatRead() ;
u8		LM35_u8Read() ;

#endif /* LM35_H_ */