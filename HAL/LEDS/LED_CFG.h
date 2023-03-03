/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LEDS_CFG.h		*/
/****************************************************************/

#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "LED.h"

#define NUMBER_OF_LEDS 4

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}PORTx;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	PIN16,
	PIN17,
	PIN18,
	PIN19,
	PIN20,
	PIN21,
	PIN22,
	PIN23,
	PIN24,
	PIN25,
	PIN26,
	PIN27,
	PIN28,
	PIN29,
	PIN30,
	PIN31,
	PIN32
}PINx;


typedef enum
{
	SOURCE ,
	SINK
}LED_STATE;


typedef struct
{
	
	PORTx  Port ;
	PINx   Pin  ;
	LED_STATE  State;
	LED_ID Num  ;
}LED_CONFIG;

LED_CONFIG Config_LED[NUMBER_OF_LEDS]  ;



#endif /* LED_CFG_H_ */



/**********************************************************************************************************************
 *  END OF FILE: LED_CFG.h
 *********************************************************************************************************************/
