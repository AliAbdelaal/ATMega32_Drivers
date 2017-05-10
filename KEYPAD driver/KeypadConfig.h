/*
 * KeypadConfig.h
 *
 * Created: 20-Oct-15 12:20:49 AM
 *  Author: LENOVO
 */ 


#ifndef KEYPADCONFIG_H_
#define KEYPADCONFIG_H_
#include "StdTypes.h"
#include "DIO.h"
#define ROWS_NUM 4
#define COL_NUM 3
typedef struct {
	u8 KeypadPort;
	u8 RowsMask;
	u8 ColsMask;
	}KeypadConfigType;
extern KeypadConfigType KeypadConfigData ;
extern char keys[ROWS_NUM ][ COL_NUM] ;

#endif /* KEYPADCONFIG_H_ */