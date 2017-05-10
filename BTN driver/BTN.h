/*
 * BTN.h
 *
 * Created: 10/9/2015 7:46:16 PM
 *  Author: mido4
 */ 


#ifndef BTN_H_
#define BTN_H_

#include "DIO.h"

#define BTN_ACTIVE 0x00
#define BTN_INACTIVE 0x01

void BTN_Init(void);
u8 Btn_Read(u8 BtnId);



#endif /* BTN_H_ */