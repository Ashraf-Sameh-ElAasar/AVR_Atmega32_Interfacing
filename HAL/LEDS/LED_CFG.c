/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LEDS Configurations.c						*/
/****************************************************************/

#include "LED.h"
#include "LED_CFG.h"

LED_CONFIG LEDS[NUMBER_OF_LEDS]  = {
	
	{
		.Port = PORTB ,
		.Pin  = PIN7  ,
		.State = SOURCE ,
		.Num   = RED
		
	} ,
	
	{
		.Port = PORTA ,
		.Pin  = PIN5  ,
		.State = SOURCE ,
		.Num   = BLUE
	} ,
	
	{
		.Port = PORTA ,
		.Pin  = PIN4  ,
		.State = SOURCE ,
		.Num   = GREEN
	} ,
	
	{
		.Port = PORTA ,
		.Pin  = PIN6  ,
		.State = SOURCE ,
		.Num   = YELLOW
	}
	
};

/**********************************************************************************************************************
 *  END OF FILE: LED_CFG.c
 *********************************************************************************************************************/
