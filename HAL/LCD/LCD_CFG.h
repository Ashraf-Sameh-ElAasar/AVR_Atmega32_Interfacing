/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LCD Configurations.c			*/
/****************************************************************/

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "LCD.h"
#include "std_types.h"


#define NO_CSTOM_CHAR			8
#define NO_CSTOM_CHAR_BYTES		8
#define NUMBER_OF_LCDS 1

typedef enum{
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



typedef struct {
	PORTx LCD_Control_PORT ;
	PORTx LCD_DATA_PORT ;
	u16   EN_Delay ;
	PINx  EN ;
	PINx  RS ;
	PINx  D4 ;
	PINx  D5 ;
	PINx  D6 ;
	PINx  D7 ;
}LCD_CONFIG;

#define LCD_RS_PORT				DIO_PORTA
#define LCD_RS_CHANNEL			DIO_PIN3

#define LCD_RW_PORT             DIO_PORTC
#define LCD_RW_CHANNEL          DIO_PIN1

#define LCD_EN_PORT     		DIO_PORTA
#define LCD_EN_CHANNEL			DIO_PIN2

#define LCD_D4_PORT				DIO_PORTB
#define LCD_D4_CHANNEL			DIO_PIN0

#define LCD_D5_PORT				DIO_PORTB
#define LCD_D5_CHANNEL			DIO_PIN1

#define LCD_D6_PORT				DIO_PORTB
#define LCD_D6_CHANNEL			DIO_PIN2

#define LCD_D7_PORT				DIO_PORTB
#define LCD_D7_CHANNEL			DIO_PIN4


LCD_CONFIG Config_LCD[NUMBER_OF_LCDS] ;


#endif /* LCD_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: LCD_CFG.h
 *********************************************************************************************************************/
