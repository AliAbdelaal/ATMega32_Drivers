#ifndef DISP_LCFG_H_
#define DISP_LCFG_H_
#include "DISP_Confg.h"

typedef struct
{
	u8 Seg_Port ;
	u8 Seg_Data ;
	u8 Seg_enable_Port;
	u8 Seg_enable_Mask;
	}SEG_ConfigType;
extern SEG_ConfigType SEG_ConfigData[SEG_MAX_NUM] ;




#endif /* DISP_LCFG_H_ */