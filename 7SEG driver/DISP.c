#include "DISP.h"
#include "DISP_LCfong.h"

void DISP_Init(void){
	u8 LoopIndex;
	u8 SegPort , SegEnPort ;
	u8 SegDataMask , SegEnMask ;
	for(LoopIndex=0;LoopIndex<SEG_MAX_NUM;LoopIndex++)
	{
		SegPort = SEG_ConfigData[LoopIndex].Seg_Port ;
		SegEnPort = SEG_ConfigData[LoopIndex].Seg_enable_Port;
		SegDataMask = SEG_ConfigData[LoopIndex].Seg_Data ;
		SegEnMask= SEG_ConfigData[LoopIndex].Seg_enable_Mask;
		DIO_InitPortDirection(SegPort,SegDataMask,SegDataMask);
		DIO_InitPortDirection(SegEnPort,SegEnMask,SegEnMask);
	}	
}

void DISP_Data(u8 SegID , u8 Data)
{
	u8 SegPort  , LoopIndex, SegEnPort , SegDataMask , SegEnMask ;
	Data = (Data<<4); 
	for(LoopIndex=0;LoopIndex<SEG_MAX_NUM ; LoopIndex++)
	{
		if(LoopIndex==SegID) continue;
		u8 Port = SEG_ConfigData[LoopIndex].Seg_enable_Port;
		u8 EnableMask = SEG_ConfigData[LoopIndex].Seg_enable_Mask;
		DIO_WritePort(Port ,0x00,EnableMask);
	}
	SegPort      = SEG_ConfigData[SegID].Seg_Port ;
	SegDataMask = SEG_ConfigData[SegID].Seg_Data;
	SegEnMask   = SEG_ConfigData[SegID].Seg_enable_Mask;
	SegEnPort   = SEG_ConfigData[SegID].Seg_enable_Port;
	DIO_WritePort(SegPort,Data,SegDataMask);
	DIO_WritePort(SegEnPort,SegEnMask,SegEnMask);
}
