/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: MCAL             ******************/
/***************     SWC: TIMER   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../PORT/PORT_interface.h"
#include "../DIO/DIO_interface.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

void (*TIMER0_pvIntFunc)(void)=NULL;
u32 OverFlowCounter=0;

void TIMER0_u8IntEnable(void){

	SET_BIT(TIMSK,TIMSK_TOIE0);
}

void TIMER0_u8IntDisable(void){

	CLR_BIT(TIMSK,TIMSK_TOIE0);
}

void TIMER0_u8Init(void){
	TCNT0=0;
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}

void TIMER0_u8Stop(void){

	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}

u8 TIMER0_u8SetPreScaler(u8 Copy_u8PreScaler){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8PreScaler){
	case NO_PRE_SCALER:
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;

	case CLK_8:
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;

	case CLK_64:
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
		break;

	case CLK_256:
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;

	case CLK_1024:
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);
		break;

	default:
		Local_u8ErrorState=NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 TIMER0_u8DelayBusyWait(u32 Copy_u8Delay){
	u8 Local_u8ErrorState=OK;
	u32 Local_u32OverFlowCounter=0;
	if(Copy_u8Delay<=0){
		Local_u8ErrorState=NOK;
		return Local_u8ErrorState;
	}
	if(Copy_u8Delay<256){
		TCNT0=256-Copy_u8Delay;
		OverFlowCounter=1;
		Local_u32OverFlowCounter=1;
	}
	else if(Copy_u8Delay==256){
		TCNT0=0;
		OverFlowCounter=1;
		Local_u32OverFlowCounter=1;
	}
	else if(Copy_u8Delay>256){
		OverFlowCounter=Copy_u8Delay/256;
		Local_u32OverFlowCounter=Copy_u8Delay/256;
		u32 Local_u8InitialVal=256-(Copy_u8Delay/Local_u32OverFlowCounter);
		TCNT0=Local_u8InitialVal;
	}
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
	u32 Local_u8OverFlowNum=0;
	while(Local_u8OverFlowNum<Local_u32OverFlowCounter){
		while(GET_BIT(TIFR,TIFR_TOV0)==0);
		SET_BIT(TIFR,TIFR_TOV0);
		Local_u8OverFlowNum++;
	}
	//TIMER0_u8Stop();

	return Local_u8ErrorState;
}

u8 TIMER0_u8DelayInt(u32 Copy_u8Delay){
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Delay<=0){
		Local_u8ErrorState=NOK;
		return Local_u8ErrorState;
	}
	if(Copy_u8Delay<256){
		TCNT0=256-Copy_u8Delay;
		OverFlowCounter=1;
	}
	else if(Copy_u8Delay==256){
		TCNT0=0;
		OverFlowCounter=1;
	}
	else if(Copy_u8Delay>256){
		OverFlowCounter=Copy_u8Delay/256;
		u32 Local_u8InitialVal=256-(Copy_u8Delay/OverFlowCounter);
		TCNT0=Local_u8InitialVal;
	}
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

	return Local_u8ErrorState;
}

u8 TIMER0_u8IntSetCallBack(void (*Copy_pvIntFunc)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvIntFunc!=NULL){
		TIMER0_pvIntFunc=Copy_pvIntFunc;
	}
	else{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	static u32 Local_u8Counter=0;
	Local_u8Counter++;
	if(TIMER0_pvIntFunc!=NULL && Local_u8Counter==OverFlowCounter){
		TIMER0_pvIntFunc();
		TIMER0_u8Stop();
	}
	else{

	}
}
