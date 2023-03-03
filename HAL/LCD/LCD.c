/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LCD Prog.c			*/
/****************************************************************/
#define F_CPU 16000000UL
#include "LCD.h"
#include "LCD_CFG.h"
#include "DIO.h"
#include <util/delay.h>

extern u8 customChar[NO_CSTOM_CHAR][NO_CSTOM_CHAR_BYTES];


void LCD_voidDATA(u8 data){
	if(data & 1)
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D4 , STD_HIGH );
	}
	
	else
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D4 , STD_LOW );
	}
	
	if(data & 2)
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D5 , STD_HIGH );
	}
	
	else
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D5 , STD_LOW );
	}
	
	if(data & 4)
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D6 , STD_HIGH );
	}
	
	else
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D6 , STD_LOW );
	}
	
	if(data & 8)
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D7 , STD_HIGH );
	}
	
	else
	{
		dio_voidWriteChannel(Config_LCD->LCD_DATA_PORT, Config_LCD->D7 , STD_LOW );
	}
	
}

void LCD_voidCMD(u8 CMD){
	// Select Command Register
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->RS , STD_LOW );
	// Move The Command Data To LCD
	LCD_voidDATA(CMD);
	// Send The EN Clock Signal
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_HIGH);
	_delay_us(500);
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_LOW);
}

void LCD_voidInit(void){
	// IO Pin Configurations
	
	dio_voidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D4 , OUTPUT);
	dio_voidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D5 , OUTPUT);
	dio_voidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D6 , OUTPUT);
	dio_voidConfigChannel(Config_LCD->LCD_DATA_PORT ,Config_LCD->D7 , OUTPUT);
	dio_voidConfigChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->RS , OUTPUT);
	dio_voidConfigChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , OUTPUT);
	// The Initiate Procedure
	LCD_voidDATA(0x00);
	_delay_ms(30);
	_delay_us(500);
	LCD_voidCMD(0x03);
	_delay_ms(5);
	LCD_voidCMD(0x03);
	_delay_us(150);
	LCD_voidCMD(0x03);
	LCD_voidCMD(0x02);
	LCD_voidCMD(0x02);
	LCD_voidCMD(0x08);
	LCD_voidCMD(0x00);
	LCD_voidCMD(0x0C);
	LCD_voidCMD(0x00);
	LCD_voidCMD(0x06);
	LCD_voidClear();
}

void LCD_voidGotoXY(lcd_row_t Copy_u8XPos, lcd_column_t Copy_u8YPos)
{
	u8 Local_u8Address = 0;

	//	Adresses start with address 0
	if(Copy_u8XPos == LCD_u8_FIRST_ROW)
	{
		Local_u8Address = Copy_u8YPos;
	}

	//	Adresses start with address 0x40
	else if(Copy_u8XPos == LCD_u8_SECOND_ROW)
	{
		Local_u8Address = 0x40 + Copy_u8YPos;
	}

	//	Setting the 8th bit 1 for the command (Datasheet)
	SET_BIT(Local_u8Address, 7);
	//	Sending the SET DDRAM address command
	LCD_voidCMD(Local_u8Address);
}

void LCD_voidWrite_Char(u8 Data){
	u8 LCD_Low,LCD_High;
	LCD_Low = Data & 0x0F;
	LCD_High = Data & 0xF0;
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->RS , STD_HIGH );  // select data mode
	LCD_voidDATA(LCD_High>>4);
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_HIGH);
	_delay_us(500);
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_LOW);
	_delay_us(500);
	LCD_voidDATA(LCD_Low);
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_HIGH);
	_delay_us(500);
	dio_voidWriteChannel(Config_LCD->LCD_Control_PORT ,Config_LCD->EN , STD_LOW);
	_delay_us(500);
}

void LCD_voidWrite_String(u8 *str){
	while (*str != '\0')
	{
		LCD_voidWrite_Char(*str);
		str++;
	}
}

void LCD_voidClear(void){
	LCD_voidCMD(0);
	LCD_voidCMD(1);
}

void lcd_voidDisplyNum(u16 num)
{
	u8 num_to_char_array[100], iterator = 0;
	while(num != 0)
	{
		num_to_char_array[iterator] = (u8)(num % 10);
		num /= 10;
		iterator++;
	}
	for(;iterator > 0; iterator--)
	{
		LCD_voidDATA('0' + (num_to_char_array[iterator-1]));
	}
}

void LCD_voidSet_Cursor(u8 row, u8 column) { // r = ROW , c = Column
	u8 Temp;
	u8 LCD_Low,LCD_High;
	if(row == 1)
	{
		Temp = 0x80 + column - 1; //0x80 is used to move the cursor
		LCD_High = Temp >> 4;
		LCD_Low = Temp & 0x0F;
		LCD_voidCMD(LCD_High);
		LCD_voidCMD(LCD_Low);
	}
	if(row == 2)
	{
		Temp = 0xC0 + column - 1;
		LCD_High = Temp >> 4;
		LCD_Low = Temp & 0x0F;
		LCD_voidCMD(LCD_High);
		LCD_voidCMD(LCD_Low);
	}
	if(row == 3)
	{
		Temp = 0x90 + column - 1;
		LCD_High = Temp >> 4;
		LCD_Low = Temp & 0x0F;
		LCD_voidCMD(LCD_High);
		LCD_voidCMD(LCD_Low);
	}
	if(row == 4)
	{
		Temp = 0xD0 + column - 1;
		LCD_High = Temp >> 4;
		LCD_Low = Temp & 0x0F;
		LCD_voidCMD(LCD_High);
		LCD_voidCMD(LCD_Low);
	}
}

void LCD_voidSR(void)
{ //shift all the display to right
	LCD_voidCMD(0x01);
	LCD_voidCMD(0x0C);
}

void LCD_voidSL(void)
{ //shift all the display to Left
	LCD_voidCMD(0x01);
	LCD_voidCMD(0x08);
}

void lcd_voidCustomWrite(void)
{
	u8 loc_ByteIndex=0;
	u8 loc_CharIndx=0;
	
	for (loc_CharIndx=0;loc_CharIndx<NO_CSTOM_CHAR;loc_CharIndx++)
	{
		LCD_voidCMD(_LCD_CGRAM_START_ADDRESS +(loc_CharIndx*8));
		for (loc_ByteIndex =0; loc_ByteIndex<NO_CSTOM_CHAR_BYTES;loc_ByteIndex++)
		{
			LCD_voidWrite_Char(customChar[loc_CharIndx][loc_ByteIndex]);
		}
	}
}

void enablePulse(void)
{
	dio_voidWriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_HIGH);
	_delay_us(1);
	dio_voidWriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_LOW);
	_delay_ms(2);
}

void lcd_vidCustomWrite(void)
{
	u8 loc_ByteIndex=0;
	u8 loc_CharIndx=0;
	
	for (loc_CharIndx=0;loc_CharIndx<NO_CSTOM_CHAR;loc_CharIndx++)
	{
		LCD_voidCMD(_LCD_CGRAM_START_ADDRESS +(loc_CharIndx*8));
		for (loc_ByteIndex =0; loc_ByteIndex<NO_CSTOM_CHAR_BYTES;loc_ByteIndex++)
		{
			LCD_voidWrite_Char(customChar[loc_CharIndx][loc_ByteIndex]);
		}
	}
}


void LCD_voidWriteSpecialCharacter(u8* Copy_u8Pattern, u8 Copy_u8PatternNumber, u8 Copy_XPos, u8 Copy_YPos)
{
	u8 Local_u8Address, Local_u8PatternCounter;

	//	1- Calculate the required address of CGRAM
	Local_u8Address = Copy_u8PatternNumber * 8;

	//	2- Set CGRAM Address the 7th bit 1 for the command (Datasheet)
	SET_BIT(Local_u8Address, 6);
	LCD_voidCMD(Local_u8Address);

	//	3- Write the required pattern inside the CGRAM
	for(Local_u8PatternCounter = 0; Local_u8PatternCounter < 8; Local_u8PatternCounter++)
	{
		LCD_voidDATA(Copy_u8Pattern[Local_u8PatternCounter]);
	}

	//	4- Shift the address counter to the DDRAM
	LCD_voidGotoXY(Copy_XPos, Copy_YPos);

	//	5- Display the CGRAM pattern on the LCD
	LCD_voidDATA(Copy_u8PatternNumber);
}

/**********************************************************************************************************************
 *  END OF FILE: LCD.c
 *********************************************************************************************************************/
