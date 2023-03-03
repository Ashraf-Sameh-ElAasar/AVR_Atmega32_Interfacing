/****************************************************************/
/*   Author             :    Ashraf Sameh ElAasar				*/
/*	 Date 				:    28 Feb 2023 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   LCD Interface.h			*/
/****************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"
#include "LCD_TYPES.h"

void LCD_voidDATA(u8 data);
void LCD_voidCMD(u8 CMD);
void LCD_voidInit(void);
void LCD_voidWrite_Char(u8 Data);
void LCD_voidWrite_String(u8 *str);
void lcd_voidDisplyNum(u16 num);
void LCD_voidClear(void);
void LCD_voidSet_Cursor(u8 row, u8 column);
void enablePulse(void);
void LCD_voidSR(void);
void LCD_voidSL(void);
void lcd_voidCustomWrite(void);
void LCD_voidGotoXY(lcd_row_t Copy_u8XPos, lcd_column_t Copy_u8YPos);



#endif /* LCD_H_ */

/**********************************************************************************************************************
 *  END OF FILE: LCD.h
 *********************************************************************************************************************/
