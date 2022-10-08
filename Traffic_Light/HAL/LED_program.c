/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: HAL              ******************/
/***************     SWC: LED   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

u8 LED_u8TurnOn(LED* Copy_structLedProp){
	u8 Local_u8ErrorState=0;
	if(Copy_structLedProp->LED_u8Pin<=DIO_u8PIN7){
		if(Copy_structLedProp->LED_u8ConnType==LED_u8SOURCE){
			switch(Copy_structLedProp->LED_u8Port){
			case DIO_u8PORTA :DIO_u8SetPinValue(DIO_u8PORTA ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			case DIO_u8PORTB :DIO_u8SetPinValue(DIO_u8PORTB ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			case DIO_u8PORTC :DIO_u8SetPinValue(DIO_u8PORTC ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			case DIO_u8PORTD :DIO_u8SetPinValue(DIO_u8PORTD ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			default:Local_u8ErrorState=1;break;
			}
		}
		else if(Copy_structLedProp->LED_u8ConnType==LED_u8SYNC){
			switch(Copy_structLedProp->LED_u8Port){
			case DIO_u8PORTA :DIO_u8SetPinValue(DIO_u8PORTA ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			case DIO_u8PORTB :DIO_u8SetPinValue(DIO_u8PORTB ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			case DIO_u8PORTC :DIO_u8SetPinValue(DIO_u8PORTC ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			case DIO_u8PORTD :DIO_u8SetPinValue(DIO_u8PORTD ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			default:Local_u8ErrorState=1;break;
			}
		}
		else{
			Local_u8ErrorState=1;
		}
	}
	else{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 LED_u8TurnOff(LED *Copy_structLedProp){
	u8 Local_u8ErrorState=0;
	if(Copy_structLedProp->LED_u8Pin<=DIO_u8PIN7){
		if(Copy_structLedProp->LED_u8ConnType==LED_u8SOURCE){
			switch(Copy_structLedProp->LED_u8Port){
			case DIO_u8PORTA :DIO_u8SetPinValue(DIO_u8PORTA ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			case DIO_u8PORTB :DIO_u8SetPinValue(DIO_u8PORTB ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			case DIO_u8PORTC :DIO_u8SetPinValue(DIO_u8PORTC ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			case DIO_u8PORTD :DIO_u8SetPinValue(DIO_u8PORTD ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_LOW);break;
			default:Local_u8ErrorState=1;break;
			}
		}
		else if(Copy_structLedProp->LED_u8ConnType==LED_u8SYNC){
			switch(Copy_structLedProp->LED_u8Port){
			case DIO_u8PORTA :DIO_u8SetPinValue(DIO_u8PORTA ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			case DIO_u8PORTB :DIO_u8SetPinValue(DIO_u8PORTB ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			case DIO_u8PORTC :DIO_u8SetPinValue(DIO_u8PORTC ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			case DIO_u8PORTD :DIO_u8SetPinValue(DIO_u8PORTD ,Copy_structLedProp->LED_u8Pin,DIO_u8PIN_HIGH);break;
			default:Local_u8ErrorState=1;break;
			}
		}
		else{
			Local_u8ErrorState=1;
		}
	}
	else{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

void LED_voidToggle(LED* Copy_u8LED)
{
	u8 Local_u8PinState;
	DIO_u8GetPinValue(Copy_u8LED->LED_u8Port,Copy_u8LED->LED_u8Pin,&Local_u8PinState);

	switch(Copy_u8LED->LED_u8ConnType)
	{
		case LED_u8SOURCE:
			switch(Local_u8PinState)
			{
				case 0: LED_u8TurnOn(Copy_u8LED); break;
				case 1: LED_u8TurnOff(Copy_u8LED); break;
			}
			break;
		case LED_u8SYNC:
			switch(Local_u8PinState)
			{
				case 0: LED_u8TurnOff(Copy_u8LED); break;
				case 1: LED_u8TurnOn(Copy_u8LED); break;
			}
			break;
	}
}
