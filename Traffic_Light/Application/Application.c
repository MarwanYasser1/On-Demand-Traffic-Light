/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: APPLICATION      ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../HAL/LED_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"

void IntISR(void);
void NormalMode(void);

#define GREEN_CAR	1
#define YELLOW_CAR	2
#define RED_CAR		3

u8 CarLight=GREEN_CAR;
u8 CarLight_Last=GREEN_CAR;
LED LED_GREEN_CARS = {DIO_u8PORTA,DIO_u8PIN0,LED_u8SOURCE};
LED LED_YELLOW_CARS = {DIO_u8PORTA,DIO_u8PIN1,LED_u8SOURCE};
LED LED_RED_CARS = {DIO_u8PORTA,DIO_u8PIN2,LED_u8SOURCE};

LED LED_GREEN_PEDESTRIAN = {DIO_u8PORTB,DIO_u8PIN0,LED_u8SOURCE};
LED LED_YELLOW_PEDESTRIAN = {DIO_u8PORTB,DIO_u8PIN1,LED_u8SOURCE};
LED LED_RED_PEDESTRIAN = {DIO_u8PORTB,DIO_u8PIN2,LED_u8SOURCE};

void AppInit(void){
	PORT_voidInit();
	TIMER0_u8Init();
	GIE_viodEnable();
	EXTI_voidInt0Init();
	EXTI_u8Int0SetCallBack(&IntISR);
	LED_u8TurnOff(&LED_GREEN_PEDESTRIAN);
	LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
	LED_u8TurnOn(&LED_RED_PEDESTRIAN);
}

void AppStart(void){
	NormalMode();
}


void IntISR(void){
	TIMER0_u8DelayBusyWait(1000000);
	u8 Button=0;
	DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Button);
	if(Button==0){
		//DO NOTHING
	}
	else{
		switch(CarLight){
		case GREEN_CAR ... YELLOW_CAR:
		LED_u8TurnOff(&LED_GREEN_CARS);
		LED_u8TurnOn(&LED_YELLOW_CARS);
		LED_u8TurnOff(&LED_RED_CARS);

		LED_u8TurnOff(&LED_GREEN_PEDESTRIAN);
		LED_u8TurnOn(&LED_YELLOW_PEDESTRIAN);
		LED_u8TurnOn(&LED_RED_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);

		LED_u8TurnOff(&LED_GREEN_CARS);
		LED_u8TurnOff(&LED_YELLOW_CARS);
		LED_u8TurnOn(&LED_RED_CARS);

		LED_u8TurnOn(&LED_GREEN_PEDESTRIAN);
		LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
		LED_u8TurnOff(&LED_RED_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(5000000);
		break;

		case RED_CAR:
			LED_u8TurnOff(&LED_GREEN_CARS);
			LED_u8TurnOff(&LED_YELLOW_CARS);
			LED_u8TurnOn(&LED_RED_CARS);

			LED_u8TurnOn(&LED_GREEN_PEDESTRIAN);
			LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
			LED_u8TurnOff(&LED_RED_PEDESTRIAN);
			TIMER0_u8DelayBusyWait(5000000);
			break;
		}
		LED_u8TurnOff(&LED_GREEN_CARS);
		LED_u8TurnOn(&LED_YELLOW_CARS);
		LED_u8TurnOff(&LED_RED_CARS);

		LED_u8TurnOn(&LED_GREEN_PEDESTRIAN);
		LED_u8TurnOn(&LED_YELLOW_PEDESTRIAN);
		LED_u8TurnOff(&LED_RED_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		LED_voidToggle(&LED_YELLOW_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);

		LED_u8TurnOn(&LED_GREEN_CARS);
		LED_u8TurnOff(&LED_YELLOW_CARS);
		LED_u8TurnOff(&LED_RED_CARS);

		LED_u8TurnOff(&LED_GREEN_PEDESTRIAN);
		LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
		LED_u8TurnOn(&LED_RED_PEDESTRIAN);
		CarLight_Last=CarLight;
		CarLight=GREEN_CAR;
	}
}

void NormalMode(void){
	switch(CarLight){
	case GREEN_CAR:
		//GREEN ON
		CarLight=GREEN_CAR;
		LED_u8TurnOn(&LED_GREEN_CARS);
		LED_u8TurnOff(&LED_YELLOW_CARS);
		LED_u8TurnOff(&LED_RED_CARS);
		LED_u8TurnOff(&LED_GREEN_PEDESTRIAN);
		LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
		LED_u8TurnOff(&LED_RED_PEDESTRIAN);
		CarLight_Last=GREEN_CAR;

		TIMER0_u8DelayBusyWait(5000000);
		CarLight=YELLOW_CAR;

		break;
	case YELLOW_CAR:
		//YELLOW ON
		CarLight=YELLOW_CAR;
		LED_u8TurnOff(&LED_GREEN_CARS);
		LED_u8TurnOn(&LED_YELLOW_CARS);
		LED_u8TurnOff(&LED_RED_CARS);
		LED_u8TurnOff(&LED_GREEN_PEDESTRIAN);
		LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
		LED_u8TurnOn(&LED_RED_PEDESTRIAN);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		TIMER0_u8DelayBusyWait(1000000);
		LED_voidToggle(&LED_YELLOW_CARS);
		switch(CarLight_Last){
		case GREEN_CAR :
			CarLight=RED_CAR;
			break;

		case YELLOW_CAR ... RED_CAR:
		CarLight=GREEN_CAR;
		break;
		}

		TIMER0_u8DelayBusyWait(1000000);

		break;
		case RED_CAR:
			//RED ON
			CarLight=RED_CAR;
			LED_u8TurnOff(&LED_GREEN_CARS);
			LED_u8TurnOff(&LED_YELLOW_CARS);
			LED_u8TurnOn(&LED_RED_CARS);

			LED_u8TurnOn(&LED_GREEN_PEDESTRIAN);
			LED_u8TurnOff(&LED_YELLOW_PEDESTRIAN);
			LED_u8TurnOff(&LED_RED_PEDESTRIAN);
			CarLight_Last=RED_CAR;

			TIMER0_u8DelayBusyWait(5000000);
			CarLight=YELLOW_CAR;

			break;
	}
}
