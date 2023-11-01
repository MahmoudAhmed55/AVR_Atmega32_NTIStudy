/*
 * DIO_Interface.h
 *
 * Created: 10/20/2023 10:47:34 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 
#ifndef UTILS_H_
#define UTILS_H_

#define READ_BIT(reg,bit)  ((reg>>bit)&1)
#define SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define CLR_BIT(reg,bit)   (reg=reg&(~(1<<bit)))
#define TOG_BIT(reg,bit)   (reg=reg^(1<<bit))

#define SET_BYTE(BYTE,VALUE)  BYTE=VALUE //SET_BYTE

#define CONC_BYTE(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0   //concatenation_config_for_byte

#define F_CPU  8000000     //cpu_cristal

#include <util/delay.h>   // delay_library

#endif /* UTILS_H_ */