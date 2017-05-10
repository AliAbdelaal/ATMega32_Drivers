/*
 * LM35 v2.c
 *
 * Created: 20-Aug-16 2:51:27 AM
 * Author : Ali
 */ 

#include "lcd_4bit.h"
#include "LM35.h"
#include <util/delay.h>

int main(void)
{
	LM35_init(0x00,5,1023) ;
	lcd_init();
    while (1) 
    {
		lcd_clrScreen() ;
		lcd_dispString("float : ");
		lcd_displayFloat(LM35_floatRead());
		lcd_gotoxy(0,1) ;
		lcd_dispString("u8 : ");
		lcd_displayInt(LM35_u8Read());
		_delay_ms(500) ;
    }
}

