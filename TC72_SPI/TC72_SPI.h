/*
 * SPI.h
 *
 * Created: 18/09/2015 02:13:51 م
 *  Author: hossam
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "StdTypes.h"
#include "TC72_SPI_Lcfg.h"


#define SSEnable DIO_WritePort(SS_Data.SSPort ,0xFF , SS_Data.SSMask)
#define SSDisable DIO_WritePort(SS_Data.SSPort ,0x00 , SS_Data.SSMask)

void SPI_vidInit(void);
u8 SPI_u8TransfereByte(u8 u8Byte);
void SPI_modInit(u8 Mode);
u16 tc72_tempRead(void);



#endif /* SPI_H_ */