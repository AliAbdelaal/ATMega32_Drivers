/*
 * LED_LConfg.h
 *
 * Created: 13-Oct-15 12:21:18 AM
 *  Author: LENOVO
 */ 


#ifndef LED_LCONFG_H_
#define LED_LCONFG_H_
#include "LED_Confg.h"
#include "DIO.h"
typedef struct{
	u8 LedPort ;
	u8 LedMask;
	}LED_CongType;

extern LED_CongType LED_ConfgData[LED_MAX_NUM];




#endif /* LED_LCONFG_H_ */