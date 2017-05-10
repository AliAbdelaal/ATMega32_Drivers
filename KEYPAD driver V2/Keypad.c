/*
 * Keypad.c
 *
 * Created: 02-Aug-16 2:17:34 AM
 *  Author: Ali
 */ 

#include "Keypad.h"
#include "DIO.h"
#include "util/delay.h"

static u8 keypad_decoder( u8 , u8 ) ;
u8 KEYPAD_map[ROWS_NUM][COL_NUM]=
{	{ '1' , '2' , '3' } , 
	{ '4' , '5' , '6' } , 
	{ '7' , '8' , '9' } ,	
	{ '*' , '0' , '#' } } ;
static u8 rowShift = 0x00 ;
static u8 colShift = 0x00 ;

void keypad_init() 
{
	u8 loopIndex = 0x00 ;
	DIO_InitPortDirection(KEYPAD_ROW_PORT , OUTPUT , KEYPAD_ROW_MASK) ;		//define the rows as output 
	DIO_InitPortDirection(KEYPAD_COL_PORT , INPUT  , KEYPAD_COL_MASK) ;		//define the cols as input 
	DIO_WritePort(KEYPAD_COL_PORT , HIGH , KEYPAD_COL_MASK) ;				//enable the pull up resistors in the col
	DIO_WritePort(KEYPAD_ROW_PORT , LOW , KEYPAD_ROW_MASK) ;				//output low on the rows 
	//find the shifted value of the col mask
	for(loopIndex = 0x01 ; ( loopIndex & KEYPAD_COL_MASK ) == 0x00 ; loopIndex<<=1 , colShift++ ) ;
	//find the shifted value of the row mask
	for(loopIndex = 0x01 ; ( loopIndex & KEYPAD_ROW_MASK ) == 0x00 ; loopIndex<<=1 , rowShift++ ) ;
}
u8   keypad_read() 
{
	u8 col = 0x00 , row = 0x00  , loopIndex = 0x00 , testMask = 0xFF;
	while(1)																//stops till a button is pressed 
	{
		while (DIO_ReadPort(KEYPAD_COL_PORT , KEYPAD_COL_MASK) == KEYPAD_COL_MASK) ;	//hold on till some button is pressed
		_delay_ms(20) ;
		if(DIO_ReadPort(KEYPAD_COL_PORT , KEYPAD_COL_MASK) != KEYPAD_COL_MASK)			//check if it was just a spike noise
		break ;
	}
	col = DIO_ReadPort( KEYPAD_COL_PORT , KEYPAD_COL_MASK );				//save the col mask which holds the desired col
	DIO_WritePort( KEYPAD_ROW_PORT , HIGH , KEYPAD_ROW_MASK ) ;				//output high on the rows
	for(loopIndex = 0x00 ; loopIndex < ROWS_NUM ; loopIndex++)				//finding the row 
	{
		testMask = 0x00 ;	
		testMask |= (1<<(rowShift+loopIndex)) ;								//a mask that shift the low voltage one bit at a time on the rows
		DIO_WritePort( KEYPAD_ROW_PORT , LOW , testMask) ;
		
		//check if the row is correct 
		if( (DIO_ReadPort( KEYPAD_COL_PORT , KEYPAD_COL_MASK)) == KEYPAD_COL_MASK)		
			row ++ ;
		else
			break; 
		
	} 
	
	//release the rows
	DIO_WritePort( KEYPAD_ROW_PORT , LOW , KEYPAD_ROW_MASK );
	
	
	//return the character
	return keypad_decoder(col , row ) ;
		 
}

static u8 keypad_decoder(u8 colMask , u8 row ) 
{
	u8 col = 0x00 ;
	u8 loopIndex = 0x00 ;
	
	//find the row value
	for( (loopIndex = (1<<colShift) ) ; ( loopIndex & (~colMask) ) == 0x00 ; loopIndex<<=1 , col++ ) ;
	 
	//return the decoded character
	return KEYPAD_map[row][col] ;
}
