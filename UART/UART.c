/*
 * UART.c
 *
 * Created: 26-Oct-15 2:17:35 AM
 *  Author: LENOVO
 */ 
#include "StdTypes.h"
#include "UART.h"
/************************************************************************/
/* register bits                                                      */
/************************************************************************/
/*UCSRA*/
#define RXC 7
#define TXC 6
#define UDRE 5
#define U2X 1
/*UCSRC*/
#define URSEL 7
#define UMSEL 6
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
/*modes*/
#define NORMAL_SPEED 0x00
#define DOUBLE_SPEED  0x20
#define SPEED NORMAL_SPEED
/*character size*/
#define BITS5 (0<<UCSZ0 | 0<<UCSZ1)
#define BITS6 (1<<UCSZ0 | 0<<UCSZ1)
#define BITS7 (0<<UCSZ0 | 1<<UCSZ1)
#define BITS8 (1<<UCSZ0 | 1<<UCSZ1)
/*important flags*/
#define UDREFLAG ((*(UART_Regs.UART_UCSRA))& 1<<UDRE)
#define RXCFLAG  ((*(UART_Regs.UART_UCSRA))& 1<<RXC)


typedef struct{
	u8 volatile *const  UART_UBRRH;
	u8 volatile *const  UART_UBRRL;
	u8 volatile *const	 UART_UCSRA;
	u8 volatile *const  UART_UCSRB ;
	u8 volatile *const  UART_UCSRC ;
	u8 volatile *const  UART_UDR ;  
	}UART_Reg;
UART_Reg UART_Regs = {
	(u8 volatile *const) 0x40,
	(u8 volatile *const) 0x29,
	(u8 volatile *const) 0x2B,
	(u8 volatile *const) 0x2A,
	(u8 volatile *const) 0x40,
	(u8 volatile *const) 0x2C
	}; 
void UART_Init(u16 baudRate , u8 StopBits , u8 DataBitsNumber)
{
	
	*(UART_Regs.UART_UBRRH) = (unsigned char)(baudRate>>8);
	*(UART_Regs.UART_UBRRL) = (unsigned char)baudRate;
	/* Enable receiver and transmitter */
	*(UART_Regs.UART_UCSRB) = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	*(UART_Regs.UART_UCSRC) = 1<<URSEL ;
	switch(StopBits)
	{
		case 2:		//2 stop bits
		*(UART_Regs.UART_UCSRC) |= 1<< USBS ;
		break;
		case 1 : 	//1 stop bit
		*(UART_Regs.UART_UCSRC) |= 0<< USBS ;
		break;
		default:
		*(UART_Regs.UART_UCSRC) |= 0<< USBS ;
		#warning "1 stop bit is asumed"
		break;
	}
	switch(DataBitsNumber)
	{
		case 5 :
		*(UART_Regs.UART_UCSRC) |= BITS5 ;
		break;
		case 6 :
		*(UART_Regs.UART_UCSRC) |= BITS6 ;
		break;
		case 7 :
		*(UART_Regs.UART_UCSRC) |= BITS7 ;
		break;
		case 8 :
		*(UART_Regs.UART_UCSRC) |= BITS8 ;
		break;
		default:
		#warning "8 bit charachter bits where selected"
		*(UART_Regs.UART_UCSRC) |= BITS8 ;
		break;
	}
}
void UART_TX(u8 data)
{
	//wait for the DATA register empty flag
	while(	UDREFLAG ==0 ) ;
	//send data to the buffer 
	*(UART_Regs.UART_UDR) = data;
	
}
u8	    UART_RX()
{
	//wait for receiving complete flag
	while(RXCFLAG == 0) ;
	//read the data
	u8 receivedData = *(UART_Regs.UART_UDR) ;
	return receivedData; 
}