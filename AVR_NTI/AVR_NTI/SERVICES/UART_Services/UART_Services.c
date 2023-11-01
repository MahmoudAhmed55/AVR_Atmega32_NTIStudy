/*
 * UART_Services.c
 *
 * Created: 10/29/2023 12:52:58 PM
 *  Author: Mahmoud Ahmed Ismail
 */ 
#include "Std_Types.h"
#include "UART_Interface.h"
#include "UART_Services.h"


void UART_Send_String(char *str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	
}

void UART_Recive_String(char*str)
{
	u8 i=0;
	str[0]=UART_Recive();
	while(str[i]!='#')
	{
		i++;
		str[i]=UART_Recive();
		
	}
	str[i]=0;
}

void UART_Send_Number(u32 num)
{
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));
	
}
u32 UART_Recive_Number(void)
{
	u8 b0=UART_Recive();
	u8 b1=UART_Recive();
	u8 b2=UART_Recive();
	u8 b3=UART_Recive();
	
	u32 num=(u32)b0|(u32)b1<<8 |(u32)b2<<16|(u32)b3<<24;
	return num;
	
}

void UART_Send_Number2(u32 num)
{
	u8*p=(u8*)&num;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
	
}
u32 UART_Recive_Number2(void)
{
	u8*p;
	u32 num;
	p=(u8*)&num;
	p[0]=UART_Recive();
	p[1]=UART_Recive();
	p[2]=UART_Recive();
	p[3]=UART_Recive();
	
	
	return num;
	
}

u8 endian_Check(void)
{
	u32 num=1;
	u8*p=(u8*)&num;
	if (*p==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

u32 endian_Convrert(u32 num)
{
	u32 new=0;
	new=num>>24|num<<24 |((num>>8)&0x0000ff0000) |((num<<8)&0x0000ff0000);
	return new;
	
}
u32 endian_Convrert2(u32 num)
{
	u32 new=0;
	u8*p=(u8*)&new;
	p[0]=num>>24;
	p[1]=num>>16;
	p[2]=num>>8;
	p[3]=num;
	
	
	return new;
	
}

void UART_SendStringCheckSum(u8*str)
{
	u8 i,l;
	u16 sum=0;
	for (l=0;str[l];l++)
	{
		sum+=str[l];
	}
	UART_Send(l);
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send((u8)sum);
	UART_Send(((u8)sum)>16);
	
}

u8 UART_ReciveStringCheckSum(u8*str)
{
	u8 l=UART_Recive();
	u8 i,b1=0,b2=0;
	u16 sum_rec=0,sum_calc=0;
	for (i=0;i<=l;i++)
	{
		str[i]=UART_Recive();
		sum_calc+=str[i];
	}
	b1=UART_Recive();
	b2=UART_Recive();
	sum_rec=b1|b2<<8;
	if (sum_calc==sum_rec)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
static void tx_func (void);
static volatile char*str_tx=NULLPTR;

void UART_Send_String_Asynch(char *str)
{
	UART_Send(str[0]);
	str_tx=str;
	UART_TX_InterruptEnable();
	UART_TX_SetCallBack(tx_func);
	
}
void tx_func (void)
{
	static u8 i=1;
	
	if (str_tx[i]!=0)
	{
		UART_SendNoBlock(str_tx[i]);
		i++;
	}
	else
	{
		i=1;
	}
}