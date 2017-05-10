/*
 * IncFile1.h
 *
 * Created: 26-Oct-15 2:17:05 AM
 *  Author: LENOVO
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

void UART_Init(u16 baudRate , u8 StopBits , u8 DataBitsNumber);
void UART_TX(u8 data);
u8	    UART_RX();



#endif /* INCFILE1_H_ */