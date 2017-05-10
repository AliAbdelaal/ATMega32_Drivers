/*
 * KeypadConfig.c
 *
 * Created: 20-Oct-15 12:21:20 AM
 *  Author: LENOVO
 */ 
#include "KeypadConfig.h"
KeypadConfigType KeypadConfigData = { PD, 0x78 , 0x07 } ;
char keys[ROWS_NUM ][ COL_NUM] = {
{
	'1' , '2' , '3'
},
{
	'4' , '5' , '6'
},
{
	'7' ,'8','9'
},
{
	'*','0','#'
}
	} ;