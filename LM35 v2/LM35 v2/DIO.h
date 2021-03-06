﻿/*
 * DIO.h
 *
 * Created: 20/8/2016
 *  Author: Ali
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "StdTypes.h"


#define PA 0x00
#define PB 0x01
#define PC 0x02
#define PD 0x03
#define OUTPUT 0xFF
#define INPUT 0x00
#define HIGH 0xFF
#define LOW  0x00

void DIO_InitPortDirection(u8 PortName,u8 PortDirection,u8 PortMask);
void DIO_WritePort(u8 PortName,u8 PortData,u8 PortMask);
u8 DIO_ReadPort(u8 PortName,u8 PortMAsk);



#endif /* DIO_H_ */