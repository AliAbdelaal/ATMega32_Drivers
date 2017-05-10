
#ifndef _LCD_4BIT_H

#define _LCD_4BIT_H


void lcd_displayChar(unsigned char data);
void lcd_init(void);
void lcd_gotoxy(unsigned char x , unsigned char y );
void lcd_clrScreen(void);
void lcd_dispString(char * ptr);
void lcd_disp_string_xy(char * ptr , int y , int x);
void lcd_displayInt (  int data);


#endif  

