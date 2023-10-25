/*
 * MAIN.C
 *
 * Created: 10/20/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 

#include "Std_Types.h"
#include "Utils.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "LCD_Interface.h"
#include "s7SEGMENT_Interface.h"
#include "Keypad_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "ADC_Interface.h"

 volatile u8 flag1=0,flag2=0;
volatile u16 read=0,volt=0;

void Interrupt_Code(void)
{
	flag1=1;
}

void ADC_Code(void)
{
	read=ADC_Read(CH_0);
	volt=ADC_VoltRead(CH_0);
	flag1=2;
}
int main(void)
{
	sei();
	DIO_Init();
	EXI_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	ADC_InterruptEnable();
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	ADC_AutoTriggered(External_Interrupt0_Request);
	EXI_SetCallBack(EX_INT0,Interrupt_Code);
	ADC_SetCallBack(ADC_Code);
	
	LCD_GoTo(0,0);
	LCD_WriteString("ExInterrupt_ADC");
	
	
	
	
    while (1) 
		{
			
			segment_display_BCD(35);
			
		}
		
}
