/*
 * LCD_Config.h
 *
 * Created: 10/21/2023 10:34:39 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_PORT  PA
#define RS        PINA4	
#define EN        PINA5

#define _8_BIT    1
#define _4_BIT    0

#define LCD_MODE  _4_BIT

#define D4  PINA0
#define D5  PINA1
#define D6  PINA2
#define D7  PINA3


#endif /* LCD_CONFIG_H_ */