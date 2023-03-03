/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LCD Configurations.c			*/
/****************************************************************/

#include "LCD.h"
#include "LCD_CFG.h"

u8 customChar[NO_CSTOM_CHAR][NO_CSTOM_CHAR_BYTES]=
{
	{0x0A,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00},	/* Heart symbol	 */
	{0x04,0x1F,0x11,0x11,0x11,0x11,0x11,0x1F},	/* Empty battery */
	{0x04,0x1F,0x11,0x11,0x11,0x11,0x1F,0x1F},	/*	20% battery  */
	{0x04,0x1F,0x11,0x11,0x11,0x1F,0x1F,0x1F},  /*	40% battery  */
	{0x04,0x1F,0x11,0x11,0x1F,0x1F,0x1F,0x1F},	/*	60% battery  */
	{0x04,0x1F,0x11,0x1F,0x1F,0x1F,0x1F,0x1F},	/*	80% battery  */
	{0x04,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F},	/*	100% battery */
	{0x00,0x00,0x01,0x01,0x05,0x05,0x15,0x15},	/*	Mobile Signal*/
};


LCD_CONFIG Config_LCD[NUMBER_OF_LCDS] = 
{
	
	{
		.LCD_Control_PORT = PORTA ,
		.LCD_DATA_PORT    = PORTB ,
		.EN_Delay         = 500   ,
		.EN               = PIN2  ,
		.RS               = PIN3  ,
		.D4               = PIN0  ,
		.D5               = PIN1  ,
		.D6               = PIN2  ,
		.D7               = PIN4
		
	}	
	
};

/**********************************************************************************************************************
 *  END OF FILE: LCD_CFG.c
 *********************************************************************************************************************/
