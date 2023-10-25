/*
 * _7SEGMENT_Interface.h
 *
 * Created: 10/21/2023 10:17:10 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 
#include "Std_Types.h"

#ifndef s7SEGMENT_INTERFACE_H_
#define s7SEGMENT_INTERFACE_H_

void segment_display_BCD(u16 num);
void SegmentDisplay_BinaryLed(void);
void segment_display_BCD2(u16 num);
void Segment_Display_opposite(void);

#endif /* 7SEGMENT_INTERFACE_H_ */