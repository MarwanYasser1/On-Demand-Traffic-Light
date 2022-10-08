/**************************************************************/
/**************************************************************/
/***************     Author: Marwan Yasser   ******************/
/***************     Layer: MCAL             ******************/
/***************     SWC: EXTI   			 ******************/
/***************     Version: 1.00   		 ******************/
/**************************************************************/
/**************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/* Options: 1-LOW_LEVEL
 * 			2-ON_CHANGE
 * 			3-FALLING_EDGE
 * 			4-RISING_EDGE
 */

#define INI0_SENSE		FALLING_EDGE
#define INI1_SENSE		FALLING_EDGE

/* Options: 1-FALLING_EDGE
 * 			2-RISING_EDGE
 */
#define INI2_SENSE		FALLING_EDGE

/* Options: 1-ENABLED
 * 			2-DISABLED
 */
#define INI0_INITIAL_STATE		ENABLED
#define INI1_INITIAL_STATE		ENABLED
#define INI2_INITIAL_STATE		ENABLED

#endif
