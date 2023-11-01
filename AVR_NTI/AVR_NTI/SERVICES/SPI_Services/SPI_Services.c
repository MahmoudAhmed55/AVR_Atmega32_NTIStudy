/*
 * SPI_Services.c
 *
 * Created: 10/30/2023 10:37:19 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 

#include "Std_Types.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"
#include "SPI_Services.h"


volatile u8  flag3=0;

#define SLAVE_NUM      2
#define SLAVE1_PIN   PINC1
#define SLAVE2_PIN   PINC2

u8 SPI_SendReciveManySlaves(u8 data)
{
	u8 DATA=0;
	
		switch(flag3)
		{
			case 1:
			DIO_WritePin(SLAVE1_PIN,LOW);
			 DATA=SPI_SendReceive(data);
			 DIO_WritePin(SLAVE1_PIN,HIGH);
			 break;
			 
			 case 2:
			 DIO_WritePin(SLAVE2_PIN,LOW);
			 DATA=SPI_SendReceive(data);
			 DIO_WritePin(SLAVE2_PIN,HIGH);
			 break;
			 
		}
	
	return DATA;
}