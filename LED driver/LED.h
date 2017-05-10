/*
 * LED.h
 *
 * Created: 13-Oct-15 12:10:58 AM
 *  Author: LENOVO
 */ 


#ifndef LED_H_
#define LED_H_

#define LED_High 0x01
#define LED_Low 0x00
void LED_Init(void);
void LED_Write( u8 LedNumber , u8 LedState ) ;
u8 LED_State(u8 LedNumber) ;




#endif /* LED_H_ */