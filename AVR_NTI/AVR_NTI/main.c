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
#include "UART_Interface.h"
#include "UART_Services.h"
#include "SPI_Interface.h"
#include "SPI_Services.h"


volatile u8 input=0,flag=0;
volatile u8  data=0;

volatile u8 read1=0,read2=0;
volatile u16 read=0;


void rx(void)
{
	input=UART_Recive();
	if (input=='A'||input=='B'||input=='C'||input=='D'||input=='R')
	{
		DIO_WritePin(PINB2,LOW);
		if(input=='R')
		{
			flag=1;
		}
	}
	 if (input=='E'||input=='F'||input=='G'||input=='H'||input=='f'||input=='b'||input=='s'||input=='r'||input=='l'||input=='0'||input=='1'||data=='2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8'||input=='9'||input=='z')
	{
		DIO_WritePin(PINB1,LOW);
	}
	
	data=SPI_SendReceive(input);
}


int main(void)
{
	sei();
	DIO_Init();
	UART_Init();
	SPI_Init();
	LCD_Init();
	
	 UART_RX_InterruptEnable();
	 UART_RX_SetCallBack(rx);
   
  
    DIO_WritePin(PINB3,HIGH);
	LCD_GoTo(0,0);
	LCD_WriteString("****CAR_PROJECT*****");
	LCD_GoTo(1,0);
	LCD_WriteString("DOOR:");
	LCD_WriteString("OF1");
	LCD_WriteString(" OF2");
	LCD_WriteString(" OF3");
	LCD_WriteString(" OF4");
	LCD_GoTo(2,0);
	LCD_WriteString("TEMP_SENSOR=");
	LCD_GoTo(3,0);
	LCD_WriteString("MOTOR_DIR:");
	LCD_GoTo(3,11);
	LCD_WriteString("|");
	LCD_GoTo(3,12);
	LCD_WriteString("SPEED:");
    while (1) 
		{
				if(flag==1)
				{
					data=data<<1;
					LCD_GoTo(2,13);
					LCD_WriteString("       ");
					LCD_GoTo(2,13);
					LCD_WriteNumber(data);
					LCD_WriteString(" C");
					
					flag=0;
				}
			switch(input)
			{
				//servo_doors
				case 'A':
				LCD_GoTo(1,5);
				LCD_WriteString("   ");
				LCD_GoTo(1,5);
				LCD_WriteString("ON1");
				break;
				case 'B':
				LCD_GoTo(1,9);
				LCD_WriteString("   ");
				LCD_GoTo(1,9);
				LCD_WriteString("ON2");
				break;
				case 'E':
				LCD_GoTo(1,13);
				LCD_WriteString("   ");
				LCD_GoTo(1,13);
				LCD_WriteString("ON3");
				break;
				case 'F':
				LCD_GoTo(1,17);
				LCD_WriteString("   ");
				LCD_GoTo(1,17);
				LCD_WriteString("ON4");
				break;
				case 'C':
				LCD_GoTo(1,5);
				LCD_WriteString("   ");
				LCD_GoTo(1,5);
				LCD_WriteString("OF1");
				break;
				case 'D':
				LCD_GoTo(1,9);
				LCD_WriteString("   ");
				LCD_GoTo(1,9);
				LCD_WriteString("OF2");
				break;
				case 'G':
				LCD_GoTo(1,13);
				LCD_WriteString("   ");
				LCD_GoTo(1,13);
				LCD_WriteString("OF3");
				break;
				case 'H':
				LCD_GoTo(1,17);
				LCD_WriteString("   ");
				LCD_GoTo(1,17);
				LCD_WriteString("OF4");
				break;
				
				//DC_MOTOR
				case 'f':
				LCD_GoTo(3,10);
				LCD_WriteString(" ");
				LCD_GoTo(3,10);
				LCD_WriteString("^");
				break;
				case 'b':
				LCD_GoTo(3,10);
				LCD_WriteString(" ");
				LCD_GoTo(3,10);
				LCD_WriteString("V");
				break;
				case 'r':
				LCD_GoTo(3,10);
				LCD_WriteString(" ");
				LCD_GoTo(3,10);
				LCD_WriteString(">");
				break;
				case 'l':
				LCD_GoTo(3,10);
				LCD_WriteString(" ");
				LCD_GoTo(3,10);
				LCD_WriteString("<");
				break;
				case 's':
				LCD_GoTo(3,10);
				LCD_WriteString(" ");
				LCD_GoTo(3,10);
				LCD_WriteString("S");
				break;
				
				//MOTOR_SPEED
				case '0':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("0");
				break;
				case '1':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("1");
				break;
				case '2':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("2");
				break;
				case '3':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("3");
				break;
				case '4':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("4");
				break;
				case '5':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("5");
				break;
				case '6':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("6");
				break;
				case '7':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("7");
				break;
				case '8':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("8");
				break;
				case '9':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("9");
				break;
				case 'z':
				LCD_GoTo(3,18);
				LCD_WriteString(" ");
				LCD_GoTo(3,18);
				LCD_WriteString("~");
				break;
			}
			
		
			DIO_WritePin(PINB2,HIGH);
			DIO_WritePin(PINB1,HIGH);
			
		}
}