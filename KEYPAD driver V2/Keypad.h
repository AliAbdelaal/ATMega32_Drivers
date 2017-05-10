/*
 * Keypad.h
 *
 * Created: 02-Aug-16 2:17:11 AM
 *  Author: Ali
 */ 

/************************************************************************/
/* KEYPAD AVR driver 
	this driver require DIO driver 
	please check the KEYPAD_map in the .C file to check the buttons
	feel free to modify the characters
	                                                                    */
/************************************************************************/


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "StdTypes.h"


#define KEYPAD_ROW_PORT PA
#define KEYPAD_COL_PORT PA

//note:: 
//the driver assume that the row and col pins are connected in an ascending order
//for example if the row mask is 0x70 , so the rows are connected like so 
//row1 >> pin4 , row2 >> pin5 , row3 >> pin6
//if the mask for example is 0xE0
//row1 >> pin5 , row2 >> pin6 , row3 >> pin7
//assuming 3 row keypad 



#define KEYPAD_ROW_MASK 0x78
#define KEYPAD_COL_MASK 0x07
#define ROWS_NUM 4
#define COL_NUM  3





void keypad_init() ;
u8   keypad_read() ;




#endif /* KEYPAD_H_ */