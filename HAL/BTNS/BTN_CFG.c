/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Buttons Configurations.c						*/
/****************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "BTN_CFG.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

Button_Config Buttons[NUMBER_OF_Buttons] = {
	{
		.Port = PORTD ,
		.Pin  = PIN3 ,
		.state = PULL_UP ,
		.Num   = BUTTON1
	},
	
	{
		.Port = PORTD ,
		.Pin  = PIN5 ,
		.state = PULL_UP ,
		.Num   = BUTTON2
	},
	{
		.Port = PORTD ,
		.Pin  = PIN6 ,
		.state = PULL_UP ,
		.Num   = BUTTON3
	},
	
	{
		.Port = PORTD ,
		.Pin  = PIN7 ,
		.state = PULL_UP ,
		.Num   = BUTTON4
	}
	
	
};


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: BTN_CFG.c
 *********************************************************************************************************************/
