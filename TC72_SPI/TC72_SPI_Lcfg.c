/*
 * SPI_Lcfg.c
 *
 * Created: 19/09/2015 11:01:04 ص
 *  Author: hossam
 */ 
#include "TC72_SPI_Lcfg.h"
const SPI_ConfigType SPI_InitConfig = {75000000UL,u8MODE_3,u8DOR_MSB};
SS_DataType SS_Data = { PB , 0x10 }; 