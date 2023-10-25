/*
 * LCD_Program.c
 *
 * Created: 10/21/2023 10:34:07 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 
#include "Std_Types.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "Utils.h"





#if LCD_MODE==_8_BIT

static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
void LCD_Clear(void)
{
	WriteIns(0X01);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x38);
	WriteIns(0x0c);
	LCD_Clear();
	WriteIns(0x06);
}


#else
static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);

	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Clear(void)
{
	WriteIns(0X01);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0X02);
	WriteIns(0x28);
	WriteIns(0x0c);
	LCD_Clear();
	WriteIns(0x06);
}

#endif

void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}




void LCD_GoTo(u8 line,u8 cell)
{
	if (line==0)
	{
		WriteIns(0x80+cell);
	}
	else if (line ==1)
	{
		WriteIns(0xc0+cell);
	}
	else if (line ==2)
	{
		WriteIns(0x94+cell);
	}
	else if (line ==3)
	{
		WriteIns(0xd4+cell);
	}
}


void LCD_WriteString(c8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		WriteData(str[i]);
	}
}

void LCD_WriteNumber(s32 num)
{
	c8 str[20];
	s8 i=0,j;
	
	if (num==0)
	{
		WriteData('0');
		return;
	}
	if (num<0)
	{
		WriteData('-');
		num=num*-(1);
	}
	while (num)
	{
		str[i]=num%10+'0';
		i++;
		num=num/10;
	}
	str[i]='0';
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
}
/// 4 decimal number////
void LCD_Write4D(s16 num)
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)?'1':'0');
	}
	
}

void LCD_CustomChar(u8 address,u8*pattern)
{
	WriteIns(0x40+address*8);
	
	for (u8 i=0;i<8;i++)
	{
		WriteData(pattern[i]);
	}
	WriteIns(0x80);
}

void LCD_WriteHex(u8 num)
{
	u8 HN=num>>4;
	u8 LN=num & 0X0f;
	
	if (HN<10)
	{
		LCD_WriteChar(HN+'0');
	}
	else
	{
		LCD_WriteChar(HN-10+'A');
	}
	if (LN<10)
	{
		LCD_WriteChar(LN+'0');
	}
	else
	{
		LCD_WriteChar(LN-10+'A');
	}
}