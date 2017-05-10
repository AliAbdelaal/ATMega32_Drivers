/*
 * Keypad.c
 *
 * Created: 19-Oct-15 11:14:40 PM
 *  Author: LENOVO
 */ 

#include "Keypad.h"

static u8 RowShiftValue = 0 ;
static u8 ColShiftValue = 0 ;
void Keypad_Init( void )
{
	DIO_InitPortDirection(KeypadConfigData.KeypadPort , 0xFF , KeypadConfigData.RowsMask);
	DIO_InitPortDirection(KeypadConfigData.KeypadPort , 0x00 , KeypadConfigData.ColsMask);
	DIO_WritePort(KeypadConfigData.KeypadPort, 0xFF , KeypadConfigData.ColsMask) ;
	/*row shift value finder*/
	for(u8 loopIndex = 0x01 ; loopIndex <= 0x08 ; loopIndex<<=1)
	{
		if ((KeypadConfigData.RowsMask & loopIndex )== 0)
		{
			RowShiftValue++;
		}
		else break;
	}
	/*col shif value finder*/
	for(u8 loopIndex = 0x01 ; loopIndex <= 0x08 ; loopIndex<<=1)
	{
		if ((KeypadConfigData.ColsMask & loopIndex )== 0)
		{
			ColShiftValue++;
		}
		else break;
	}
}

u8 Keypad_Read( void )
{
	u8 row = 0 , col = 0 ;
	u8 key ;
	for( row =0x01 ; row<= (1<<(ROWS_NUM-1)) ; row<<=1)
	{
		DIO_WritePort(KeypadConfigData.KeypadPort ,(~(row<<RowShiftValue)) , KeypadConfigData.RowsMask);
		u8 temp =  DIO_ReadPort(KeypadConfigData.KeypadPort , KeypadConfigData.ColsMask);
		if(temp<KeypadConfigData.ColsMask )
		{
			col = temp ;
			break ;
		}
	}
	col = ~ col ;
	col = col<<(8 - COL_NUM);
	col = col >> (8- COL_NUM) ;
	col = col>>ColShiftValue ;
	u8 RowIndex = ROWS_NUM-1 ,ColIndex = COL_NUM-1 ;
	for(u8 loopIndex =0x01 ; loopIndex<(1<<COL_NUM) ; loopIndex<<=1  )
	{
		if((loopIndex & col) == 0)
		{
			ColIndex--;
		}
		else break;
	}
	for (u8 loopIndex = 0x01 ; loopIndex<(1<<ROWS_NUM) ; loopIndex<<=1)
	{
		if((loopIndex & row) ==0)
		{
			RowIndex--;
		}
		else break;
	}
	if(RowIndex<0  || ColIndex <0  ) {return 0;}
	else {
		key = keys[RowIndex][ColIndex] ;
		return key ;
	}
	
}
u8 Keypad_Press(void)
{
	u8 value = KEYNOTPRESSED ;
	for(u8 row =0x01 ; row<= (1<<(ROWS_NUM-1)) ; row<<=1)
	{
		DIO_WritePort(KeypadConfigData.KeypadPort ,(~(row<<RowShiftValue)) , KeypadConfigData.RowsMask);
		u8 temp =  DIO_ReadPort(KeypadConfigData.KeypadPort , KeypadConfigData.ColsMask);
		if(temp<KeypadConfigData.ColsMask )
		{
			value = KEYPRESSED ;
			break ;
		}	
	}	
	return value ;
}