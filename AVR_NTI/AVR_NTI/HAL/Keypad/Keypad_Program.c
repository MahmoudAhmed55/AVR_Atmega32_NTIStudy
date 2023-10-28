/*
 * Keypad_Program.c
 *
 * Created: 10/21/2023 10:03:37 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 
#define KEYPAD_PRG 1

#include "Std_Types.h"
#include "DIO_Interface.h"
#include "KeyPad_Interface.h"
#include "Keypad_Config.h"
#include "Utils.h"



void KEYPAD_Init(void)
{
	for (u8 r=0;r<Rows;r++)
	{
		DIO_WritePin(FIRST_OUTPUT+r,HIGH);
	}
}

u8 KEYBAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	
	for (r=0;r<Rows;r++)
	{
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for (c=0;c<Cols+1;c++)
		{
			if (DIO_ReadPin(FIRST_INPUT+c)==LOW)
			{
				if (c==0)
				{
					key=KeysArr[r][c];
					_delay_ms(10);
					while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
				}
				else if (c==1)
				{
					continue;
				}
				else if (c>1)
				{
					key=KeysArr[r][c-1];
					_delay_ms(10);
					while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
				}
				
				
			}
		}
		DIO_WritePin(FIRST_OUTPUT+r,HIGH);
	}
	return key;
	
}
