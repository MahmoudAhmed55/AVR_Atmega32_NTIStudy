/*
 * UART_Services.h
 *
 * Created: 10/29/2023 12:55:27 PM
 *  Author: lenovo
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

/* sync function
*blocking
*/
void UART_Send_String(char*str);
void UART_Recive_String(char*str);

void UART_Send_Number(u32 num);
u32 UART_Recive_Number(void);

void UART_Send_Number2(u32 num);
u32 UART_Recive_Number2(void);

u8 endian_Check(void);
u32 endian_Convrert(u32 num);
u32 endian_Convrert2(u32 num);

void UART_SendStringCheckSum(u8*str);
u8 UART_ReciveStringCheckSum(u8*str);


void UART_Send_String_Asynch(char *str);



#endif /* UART_SERVICES_H_ */