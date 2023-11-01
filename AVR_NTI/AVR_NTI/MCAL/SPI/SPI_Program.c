/*
 * SPI_Program.c
 *
 * Created: 10/30/2023 5:41:03 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 
#include "Std_Types.h"
#include "MemMap.h"
#include "UTILS.h"
#include "SPI_Interface.h"


void SPI_Init(void )
{
	// SLAVE OR MASTER
	#if SPI_MODE
	SET_BIT(SPCR,MSTR);
	//clock 2mhz
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPI2X);
	#else
	CLR_BIT(SPCR,MSTR);
	#endif
	
	
	//enable
	
	SET_BIT(SPCR,SPE);
}


u8 SPI_SendReceive(u8 data)
{
	// write puffer
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	//READ PUFFER
	return SPDR;
	
}