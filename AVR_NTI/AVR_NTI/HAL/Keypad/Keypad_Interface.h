/*
 * Keypad_Interface.h
 *
 * Created: 10/21/2023 10:03:55 AM
 *  Author: Mahmoud Ahmed Ismail
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

void KEYPAD_Init(void);

u8 KEYBAD_GetKey(void);

u16 Chr_toint(u8 c);


#endif /* KEYPAD_INTERFACE_H_ */