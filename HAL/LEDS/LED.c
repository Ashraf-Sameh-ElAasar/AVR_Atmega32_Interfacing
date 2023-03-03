/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LEDS Prog.c						*/
/****************************************************************/


#include "LED.h"
#include "LED_CFG.h"
#include "DIO.h"

void LED_INIT ( void )
{
	u8 i;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++ )
	{
		dio_voidConfigChannel(Config_LED[i].Port , Config_LED[i].Pin, OUTPUT );
	}
}


void LED_ON ( LED_ID led_col )
{
	u8 i;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++)
	{
		if( led_col == Config_LED[i].Num )
		{
			switch( Config_LED[i].State )
			{
				case SOURCE :  dio_voidWriteChannel(Config_LED[i].Port , Config_LED[i].Pin , STD_HIGH );
				break ;
				case SINK   :  dio_voidWriteChannel(Config_LED[i].Port , Config_LED[i].Pin , STD_LOW );
				break ;
			}
		}
	}	
}


void LED_OFF ( LED_ID led_col)
{
	u8 i ;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++)
	{
		if(led_col == Config_LED[i].Num)
		{
			switch(Config_LED[i].State)
			{
				case SOURCE :  dio_voidWriteChannel(Config_LED[i].Port , Config_LED[i].Pin , STD_LOW ); 
				break ;
				case SINK   :  dio_voidWriteChannel(Config_LED[i].Port , Config_LED[i].Pin , STD_HIGH ); 
				break ;
			}
		}
	}
}
void LED_TOGGLE ( LED_ID led_col)
{
	u8 i ;
	for(i = 0 ; i < NUMBER_OF_LEDS ; i++)
	{
		if(led_col == Config_LED[i].Num)
		{
			dio_voidFlipChannel( Config_LED[i].Port , Config_LED[i].Pin );
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: LED.c
 *********************************************************************************************************************/
