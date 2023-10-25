/*
 * ADC.c
 *
 * Created: 10/24/2023 9:17:25 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 

#include "Std_Types.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC_Interface.h"

static void(*ADC_Fptr)(void)=NULLPTR;

u8 ADC_BusyFlag;

void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler)
{
	/*Vref*/
	switch(vref){
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	/*Prescaller*/
	ADCSRA&=0xf8;
	scaler&=0x07;
	ADCSRA|=scaler;
	
	
	/*ADC_Enable*/
	SET_BIT(ADCSRA,ADEN);
	
}

u16 ADC_Read(ADC_Channel_type ch)
{
	/*set channel MUX*/
	ADMUX&=0xe0;
	ADMUX|=ch;
	
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	
	/*w8 ADC finish */
	while (READ_BIT(ADCSRA,ADSC));
	
	return ADC;
}


/*polling conversion*/
void ADC_StartConversion(ADC_Channel_type ch)
{
	if (ADC_BusyFlag==0)
	{
		/*set channel MUX*/
		ADMUX&=0xe0;
		ADMUX|=ch;
		
		/*start conversion*/
		SET_BIT(ADCSRA,ADSC);
		ADC_BusyFlag=1;
	}
}

u8 ADC_GetPerodic(u16*pdata)
{
	if (!READ_BIT(ADCSRA,ADSC))
	{
		*pdata=ADC;
		ADC_BusyFlag=0;
		return 1;
	}
	return 0;
}


u16 ADC_GetReadNoBlock(void)
{
	return ADC;
}


u16 ADC_VoltRead(ADC_Channel_type ch)
{
	u16 volt;
	u16 adc;
	
	adc=ADC_Read(ch);
	volt =	(adc*(u32)5000)/1024; //MV
	
	return volt;
	
}

void ADC_AutoTriggered(TriggerSource_type source)
{
	SET_BIT(ADCSRA,ADATE); // Enable Auto trigger mode
	
	switch(source)
	{
		case Free_Running_mode:
		CLR_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		break;
		
		case Analog_Comparator:
		SET_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		break;
		
		case External_Interrupt0_Request:
		CLR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		break;
		
		case Timer_Counter0_Compare_Match:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
		break;
		
		case Timer_Counter0_Overflow:
		CLR_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		case Timer_Counter_Compare_Match_B:
		SET_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		case Timer_Counter1_Overflow:
		CLR_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		case Timer_Counter1_Capture_Event:
		SET_BIT(SFIOR,ADTS0);
		SET_BIT(SFIOR,ADTS1);
		SET_BIT(SFIOR,ADTS2);
		break;
		
		
	}
}

void ADC_InterruptEnable(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_InterruptDisable(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

/************************************Call back functions*********************************************/

void ADC_SetCallBack(void(*LocalPtr)(void))
{
	ADC_Fptr=LocalPtr;
}

/*******************************ISR********************************/

ISR(ADC_vect)
{
	if (ADC_Fptr!=NULLPTR)
	{
		ADC_Fptr();
	}
	
}