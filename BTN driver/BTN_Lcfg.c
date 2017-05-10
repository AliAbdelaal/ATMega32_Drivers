/*
 * BTN_Lcfg.c
 *
 * Created: 10/10/2015 4:24:41 PM
 *  Author: mido4
 */ 
#include "StdTypes.h"
#include "BTN_lcfg.h"
#include "DIO.h"
BTN_ConfigType BTN_ConfigData[BTN_MAX_NUM] =
{
	{
		PD,
		0x04	
	},
	{
		PD,
		0x02
	}
	
};
