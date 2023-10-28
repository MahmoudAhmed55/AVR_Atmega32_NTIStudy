/*
 * Timer_Config.h
 *
 * Created: 10/28/2023 10:47:03 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define  TIMER_READ()    TCNT0
#define  TIMER_Write(x)  TCNT0=x;
#define  OCR0_Write(x)   OCR0=x;




#endif /* TIMER_CONFIG_H_ */