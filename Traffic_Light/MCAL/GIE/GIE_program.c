/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: MCAL             ******************/
/***************     SWC: GIE   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_register.h"
#include "GIE_interface.h"

void GIE_viodEnable(void){
	SET_BIT(SREG,SREG_I);
}

void GIE_viodDisable(void){
	CLR_BIT(SREG,SREG_I);
}