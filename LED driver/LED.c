/*
 * LED.c
 *
 * Created: 13-Oct-15 12:11:10 AM
 *  Author: LENOVO
 */ 

#include "DIO.h"
#include "LED.h"
#include "LED_LConfg.h"

void LED_Init()
{
	u8 LoopIndex , Port , Mask ;
	for(LoopIndex=0;LoopIndex<LED_MAX_NUM;LoopIndex++)
	{
		Port = LED_ConfgData[LoopIndex].LedPort;
		Mask=LED_ConfgData[LoopIndex].LedMask;
		DIO_InitPortDirection(Port,Mask,Mask);
	}
}

void LED_Write( u8 LedNumber , u8 LedState )
{
	u8 LedPort , LedMask ;
	LedPort = LED_ConfgData[LedNumber].LedPort ;
	LedMask = LED_ConfgData[LedNumber].LedMask;
	if(LedState==LED_High)
	DIO_WritePort(LedPort,LedMask,LedMask);
	else
	DIO_WritePort(LedPort,0x00,LedMask);
}
//well be tested
u8 LED_State(u8 LedNumber) 
{
	u8 Port , Mask , State ;
	Port = LED_ConfgData[LedNumber].LedPort ;
	Mask=LED_ConfgData[LedNumber].LedMask;
	State = DIO_ReadPort(Port,Mask);
	return State>0 ? LED_High : LED_Low ;
}