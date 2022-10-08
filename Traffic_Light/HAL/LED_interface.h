/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: HAL              ******************/
/***************     SWC: LED   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_u8SYNC 0
#define LED_u8SOURCE 1

typedef struct{
	u8 LED_u8Port;
	u8 LED_u8Pin;
	u8 LED_u8ConnType;
}LED;

u8 LED_u8TurnOn(LED* Copy_structLedProp);

u8 LED_u8TurnOff(LED* Copy_structLedProp);

void LED_voidToggle(LED* Copy_u8LED);

#endif
