/*
 * LCD_LConfg.h
 *
 * Created: 25-Oct-15 1:55:32 AM
 *  Author: LENOVO
 */ 


#ifndef LCD_LCONFG_H_
#define LCD_LCONFG_H_
#include "DIO.h"
#include "StdTypes.h"
#define LCD_E 3
#define LCD_RW 2
#define LCD_RS 1


typedef struct{
	u8 CmdPort ;
	u8 DataPort ;
	u8 D47Mask;
}LCD_ConfgType;

extern LCD_ConfgType LCD_ConfgData ;



#endif /* LCD_LCONFG_H_ */