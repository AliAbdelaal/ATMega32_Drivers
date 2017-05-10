/*
 * SPI.c
 *
 * Created: 18/09/2015 02:13:40 م
 *  Author: hossam
 */ 
#include "TC72_SPI.h"
#include "DIO.h"
#include "TC72_SPI_Lcfg.h"
#include "Timer.h"
#include "avr/io.h"
typedef struct  
{
	u32 u32TempFreq;
	u8 u8RegVal;
}LutType;
LutType Lut[7] = {{F_CPU/2,4},{F_CPU/4,0},{F_CPU/8,5},{F_CPU/16,1},{F_CPU/32,6},{F_CPU/64,2},{F_CPU/128,3}};
void SPI_vidInit(void)
{
	u8 u8LoopCount;
	u8 u8EndLoop = 0;
	/*Init MOSI, MISO and SCK Directions*/
	DIO_InitPortDirection(PB,0xA0,0xE0);
	/*set SS as output*/
	DIO_InitPortDirection(SS_Data.SSPort,0xFF,SS_Data.SSMask);
	/*Get Priscaler*/
	for(u8LoopCount = 0; (u8LoopCount < 7)  && (u8EndLoop == 0) ;u8LoopCount++)
	{
		if(Lut[u8LoopCount].u32TempFreq < SPI_InitConfig.u32MaxFreq)
		{
			u8EndLoop = 1;
		}
	}
	
	SPCR = 0X00;
	SPCR |= (1<<MSTR) | (1<<SPE) | SPI_InitConfig.u8Mode | SPI_InitConfig.u8DataOrder|(Lut[u8LoopCount-1].u8RegVal & (~(1<<2)));
	SPSR = 0x00;
	SPSR |= (Lut[u8LoopCount-1].u8RegVal >> 2); 

}
u8 SPI_u8TransfereByte(u8 u8Byte)
{
	SPDR = u8Byte;
	while((SPSR&(1<<SPIF))== 0x00)
	;
	u8Byte = SPDR;
	return u8Byte;
}
void SPI_modInit(u8 Mode)
{
	SPI_vidInit();
	SSEnable ;
	SPI_u8TransfereByte(0x80);
	SPI_u8TransfereByte(Mode);
	SSDisable;
	delay_8_2_msec(15);	//because the sensor takes 150 ms to make it's first read
}
u16 tc72_tempRead(void)
{
	u16 temp ;
	SSEnable ;
	SPI_u8TransfereByte(0x02);
	temp = SPI_u8TransfereByte(0xFF);
	SSDisable;
	temp<<=8;
	SSEnable ;
	SPI_u8TransfereByte(0x01);
	temp |= SPI_u8TransfereByte(0xFF);
	SSDisable;
	return temp ;
}
