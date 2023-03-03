/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LEDS Interface.h			*/
/****************************************************************/

#ifndef LED_H_
#define LED_H_

typedef enum
{
	RED ,
	GREEN ,
	BLUE ,
	YELLOW
}LED_ID;


void LED_INIT ( void );
void LED_ON ( LED_ID led_col );
void LED_OFF ( LED_ID led_col );
void LED_TOGGLE ( LED_ID led_col );

#endif /* LED_H_ */

/**********************************************************************************************************************
 *  END OF FILE: LCD.h
 *********************************************************************************************************************/
