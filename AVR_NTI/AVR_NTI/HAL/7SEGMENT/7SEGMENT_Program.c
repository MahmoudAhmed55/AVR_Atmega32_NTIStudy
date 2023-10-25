/*
 * _7SEGMENT_Program.c
 *
 * Created: 10/21/2023 10:18:16 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 
#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "s7SEGMENT_Interface.h"
#include "s7SEGMENT_Config.h"

static u8 SegmentArr[]={0,1,2,3,4,5,6,7,16,17}; //note that digit NO4 in 7SEG connected to PB4 not PB3

void segment_display_BCD(u16 num)
{
		u16 d0=num%10;
		u16 d1=num/10;
		/*u16 d2=num/100;
		u16 d3=num/1000;*/
		
		//turn off all Digit
	/*	DIO_WritePin(PINA3,HIGH);
		DIO_WritePin(PINA2,HIGH);
		DIO_WritePin(PINB5,HIGH);
		DIO_WritePin(PINB6,HIGH);*/
		
		
		DIO_WritePin(PINA3,LOW);
		DIO_WritePort(PB,(SegmentArr[d0]|0X60));
		DIO_WritePin(PINA2,HIGH);
		_delay_ms(1);
		DIO_WritePin(PINA2,LOW);
		DIO_WritePort(PB,(SegmentArr[d1]|0X60));
		DIO_WritePin(PINA3,HIGH);
		_delay_ms(1);	
		
}
void segment_display_BCD2(u16 num)
{
		u16 d0=num%10;
		u16 d1=num/10;
		/*u16 d2=num/100;
		u16 d3=num/1000;*/
		DIO_WritePin(PINA3,HIGH);
		DIO_WritePin(PINA2,HIGH);
		
		DIO_WritePin(PINB5,LOW);
		DIO_WritePort(PB,(SegmentArr[d0]|0x20));
		DIO_WritePin(PINB6,HIGH);
		_delay_ms(1);
		DIO_WritePin(PINB6,LOW);
		DIO_WritePort(PB,(SegmentArr[d1]|0x30));
		DIO_WritePin(PINB5,HIGH);
		_delay_ms(1);	
		
}
void Segment_Display_opposite(void)
{
	u8 i=0,j=99;
	for (i=0;i<100;i++,j--)
	{
		
			//segment_display_BCD(i);
			segment_display_BCD2(j);
		
		_delay_ms(250);
		
	}

}

void SegmentDisplay_BinaryLed(void)
{
	u8 i=0,j=0;
	
	for (i=0;i<16;i++)
	{
		for (j=0;j<250;j++)
		{
			segment_display_BCD(i);
			DIO_WritePin(LED0,READ_BIT(i,0));
			DIO_WritePin(LED1,READ_BIT(i,1));
			DIO_WritePin(LED2,READ_BIT(i,2));
			DIO_WritePin(LED3,READ_BIT(i,3));
		}
		
	}
	_delay_ms(70);
}




