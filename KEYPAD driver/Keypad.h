/*
 * Keypad.h
 *
 * Created: 19-Oct-15 11:14:53 PM
 *  Author: LENOVO
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "KeypadConfig.h"
#define KEYPRESSED 0x01
#define KEYNOTPRESSED 0x00
void Keypad_Init( void );
u8 Keypad_Read( void ) ;
u8 Keypad_Press(void);



#endif /* KEYPAD_H_ */