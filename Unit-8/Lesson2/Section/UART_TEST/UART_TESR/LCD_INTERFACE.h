/*
 * LCD_INTERFACE.h
 *
 * Created: 9/11/2022 11:28:50 AM
 *  Author: AHMED ELDEEB
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_SHF_RIGHT	0
#define LCD_SHF_LEFT	1

void LCD_Init(void);
void LCD_Send_Cmd(u8 Cmd);
void LCD_Send_Char(u8 Data);
void LCD_Send_string(u8 *str);
static void LCD_Write_Half_Port(u8 value);
void LCD_CLEAR(void);
void LCD_SHIFT(u8 Shift_Direction);
void CreateCustomCharacter (u8 *Pattern, u8 Position, u8 LineNumber,u8 Location);
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position);


#endif /* LCD_INTERFACE_H_ */