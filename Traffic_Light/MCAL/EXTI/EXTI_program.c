/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: MCAL             ******************/
/***************     SWC: EXTI   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*EXTI_pvInt0Func)(void)=NULL;
void (*EXTI_pvInt1Func)(void)=NULL;
void (*EXTI_pvInt2Func)(void)=NULL;

u8 EXTI_u8IntEnable(u8 Copy_u8Interrupt){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Interrupt){
	case INT0:
		SET_BIT(GICR,GICR_INT0);
		break;

	case INT1:
		SET_BIT(GICR,GICR_INT1);
		break;

	case INT2:
		SET_BIT(GICR,GICR_INT2);
		break;

	default:
		Local_u8ErrorState=NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(u8 Copy_u8Interrupt){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Interrupt){
	case INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;

	case INT1:
		CLR_BIT(GICR,GICR_INT1);
		break;

	case INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;

	default:
		Local_u8ErrorState=NOK;
		break;
	}
	return Local_u8ErrorState;
}

void EXTI_voidInt0Init(void){
	// set sense control  for INT0
#if INI0_SENSE==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INI0_SENSE==ON_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif INI0_SENSE==FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INI0_SENSE==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#else
#error "Wrong INI0_SENSE configuration"
#endif
	//interrupt enable for INT0
#if INI0_INITIAL_STATE==ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INI0_INITIAL_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INI0_INITIAL_STATE configuration"
#endif
}

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;

	switch(INI0_SENSE){
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break;

	case ON_CHANGE:
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;

	case FALLING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break;

	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;

	default:
		Local_u8ErrorState=NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt0Func==NULL){
		Local_u8ErrorState=NULL_POINTER;
	}
	else{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	return Local_u8ErrorState;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	if(EXTI_pvInt0Func!=NULL)
		EXTI_pvInt0Func();
	else
	{

	}
}

void EXTI_voidInt1Init(void){
	// set sense control  for INT1
#if INI1_SENSE==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INI1_SENSE==ON_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif INI1_SENSE==FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INI1_SENSE==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#else
#error "Wrong INI1_SENSE configuration"
#endif
	//interrupt enable for INT1
#if INI1_INITIAL_STATE==ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INI1_INITIAL_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INI1_INITIAL_STATE configuration"
#endif
}

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;

	switch(INI1_SENSE){
	case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break;

	case ON_CHANGE:
		CLR_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
		break;

	case FALLING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break;

	case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
		break;

	default:
		Local_u8ErrorState=NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt1Func==NULL){
		Local_u8ErrorState=NULL_POINTER;
	}
	else{
		EXTI_pvInt1Func=Copy_pvInt1Func;
	}
	return Local_u8ErrorState;
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	if(EXTI_pvInt1Func!=NULL)
		EXTI_pvInt1Func();
	else
	{

	}
}

void EXTI_voidInt2Init(void){
	// set sense control  for INT2
#if INI2_SENSE==FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif INI2_SENSE==RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_INT2);
#else
#error "Wrong INI2_SENSE configuration"
#endif
	//interrupt enable for INT1
#if INI2_INITIAL_STATE==ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif INI2_INITIAL_STATE==DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INI1_INITIAL_STATE configuration"
#endif
}

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;

	switch(INI1_SENSE){
	case FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_INT2);
		break;

	case RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_INT2);
		break;

	default:
		Local_u8ErrorState=NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt2Func==NULL){
		Local_u8ErrorState=NULL_POINTER;
	}
	else{
		EXTI_pvInt2Func=Copy_pvInt2Func;
	}
	return Local_u8ErrorState;
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	if(EXTI_pvInt2Func!=NULL)
		EXTI_pvInt2Func();
	else
	{

	}
}
