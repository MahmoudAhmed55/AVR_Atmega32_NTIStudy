/*
 * Timer_Config.h
 *
 * Created: 10/28/2023 10:47:03 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

//timer0
#define  TIMER0_READ()    TCNT0
#define  TIMER0_Write(x)  TCNT0=(u8)x;
#define  OCR0_Write(x)   OCR0=(u8)x;

//timer1
#define  TIMER1_READ()    TCNT1
#define  TIMER1_Write(x)  TCNT0=(u16)x;
#define  OCR1_Write(x)   OCR0=(u16)x;

//servo motor const related to ADC depend on Prescaller we select

#define CONST_VALUE_PRESCALLER   1000  // 8MP Cristal

#endif /* TIMER_CONFIG_H_ */