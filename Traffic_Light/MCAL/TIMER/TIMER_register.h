/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: MCAL             ******************/
/***************     SWC: TIMER   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define	TIMSK	 		*((volatile u8*) 0x59)
#define TIMSK_TOIE0		0

#define	TCNT0	 		*((volatile u8*) 0x52)

#define	TCCR0	 		*((volatile u8*) 0x53)
#define TCCR0_CS00		0
#define TCCR0_CS01		1
#define TCCR0_CS02		2

#define	TIFR	 		*((volatile u8*) 0x58)
#define TIFR_TOV0		0

#endif
