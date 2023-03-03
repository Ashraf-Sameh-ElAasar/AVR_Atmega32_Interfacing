/*
 * NTI_ADC_RRIGHT.c
 *
 * Created: 2/25/2023 12:58:16 PM
 * Author : Ashraf
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "DIO.h"
#include "ADC_INT.h"
#include "LCD.h"
#include "EXTI_INT.h"
#include <util/delay.h>


int main(void)
{
	u16 Number = 0;
	ADC_voidInit();
	LCD_voidInit();
	

    /* Replace with your application code */
    while (1) 
    {
		Number = ADC_u16ReadADCInMV(0);
		
		
		lcd_voidDisplyNum(Number);
		
		_delay_ms(1000);
		LCD_voidClear();

    }
}



// ADJUSTMENT RIGHT ADJUSTMENT
// AVCC
//#define ADC_CHANNEL_NUMBER		DIO_U8_PIN_0
//#define ADC_AUTO_TRIGGER_ENABLE	DISABLED
//#define ADC_INTERRUPT_ENABLE				DISABLED
//#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING_MODE
//#define ADC_PRESCALLER				DIVID_BY_128
