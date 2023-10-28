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
#include "Timer_Interface.h"
#include "Timer_Config.h"

volatile u8 flag1=0,flag2=0;
volatile u16 read=0,volt=0;


void Ex_Interrupt(void)
{
	
	flag1=1;
}

/*ISR(TIMER0_OVF_vect)
{
	static u8 c1,c2,c3;
	
	
	DIO_TogglePin(PINB7);
	c2++;
	c3++;
	if (c1==2)
	{
		DIO_TogglePin(PINA4);
		c1=0;
	}
	if (c2==5)
	{
		DIO_TogglePin(PINA5);
		c2=0;
	}
	if (c3==10)
	{
		DIO_TogglePin(PINA6);
		c3=0;
	}
	
}*/

/*void ADC_Code(void)
{
	if (flag1==0)
	{
		read=ADC_Read(CH_0);
		DIO_TogglePin(PINC0);
	}
	else if (flag1==1)
	{
		read=ADC_Read(CH_1);
	}
	
	volt=ADC_VoltRead(CH_0);
	flag2=1;
	
}*/
int main(void)
{
	sei();
	DIO_Init();
	KEYPAD_Init();
	LCD_Init();
	//EXI_Init();
	TIMER0_Init(TIMER0_PHASECORRECT_MODE,TIMER0_SCALER_64);
	TIMER0_OC0Mode(OC0_INVERTING);
	//EXI_Enable(EX_INT0);
	//ADC_Init(VREF_AVCC,ADC_SCALER_64);
	//ADC_InterruptEnable();
	//TIMER0_OV_InterruptEnable();
	//EXI_SetCallBack(EX_INT0,Ex_Interrupt);
	//ADC_AutoTriggered(Timer_Counter0_Overflow);
	//ADC_SetCallBack(ADC_Code);
	LCD_GoTo(0,0);
	LCD_WriteString("TIMER0_KPAD_PIANO");
	u8 y=0,x=0,z=0;
    while (1) 
		{
			y=KEYBAD_GetKey();
			
}
}