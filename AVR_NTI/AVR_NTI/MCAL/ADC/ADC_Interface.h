/*
 * ADC_Interface.h
 *
 * Created: 10/24/2023 9:17:43 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "Std_Types.h"


typedef enum {
	VREF_AREF,
	VREF_AVCC,
	VREF_256V
}ADC_VoltRef_type;

typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Prescaler_type;

typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;

typedef enum{
	Free_Running_mode=0,
	Analog_Comparator,
	External_Interrupt0_Request,
	Timer_Counter0_Compare_Match,
	Timer_Counter0_Overflow,
	Timer_Counter_Compare_Match_B,
	Timer_Counter1_Overflow,
	Timer_Counter1_Capture_Event,
	}TriggerSource_type;

void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler);
u16 ADC_Read(ADC_Channel_type ch);
u16 ADC_VoltRead(ADC_Channel_type ch);
void ADC_StartConversion(ADC_Channel_type ch);
u8 ADC_GetPerodic(u16*pdata);
u16 ADC_GetReadNoBlock(void);
void ADC_AutoTriggered(TriggerSource_type source);

void ADC_InterruptEnable(void);
void ADC_InterruptDisable(void);
void ADC_SetCallBack(void(*LocalPtr)(void));



#endif /* ADC_INTERFACE_H_ */