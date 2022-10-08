/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: MCAL             ******************/
/***************     SWC: TIMER   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define NO_PRE_SCALER	1
#define CLK_8			2
#define CLK_64			3
#define CLK_256			4
#define CLK_1024		5

void TIMER0_u8Init(void);

void TIMER0_u8IntEnable(void);

void TIMER0_u8IntDisable(void);

void TIMER0_u8Stop(void);

u8 TIMER0_u8SetPreScaler(u8 Copy_u8PreScaler);

u8 TIMER0_u8IntSetCallBack(void (*Copy_pvIntFunc)(void));

u8 TIMER0_u8DelayInt(u32 Copy_u8Delay);

u8 TIMER0_u8DelayBusyWait(u32 Copy_u8Delay);

#endif
