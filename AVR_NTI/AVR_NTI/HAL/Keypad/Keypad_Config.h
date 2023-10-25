/*
 * Keypad_Config.h
 *
 * Created: 10/21/2023 10:10:41 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define Rows  4
#define Cols  4

#if KEYPAD_PRG

const u8 KeysArr[Rows][Cols]={{'7','8','9','/'}
                             ,{'4','5','6','*'}
                             ,{'1','2','3','-'}
                             ,{'c','0','=','+'}};

#endif

#define FIRST_OUTPUT  PINC2
#define FIRST_INPUT   PIND3

#define NO_KEY    'T'



#endif /* KEYPAD_CONFIG_H_ */