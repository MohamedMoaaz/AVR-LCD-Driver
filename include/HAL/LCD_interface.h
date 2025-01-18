/**
 * @file    LCD_interface.h
 * @author  Mohamed Moaaz
 * @brief   LCD interfacing file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __LCD_INTERFACE_H__
#define __LCD_INTERFACE_H__

//==============================================================================
// Macros & Defines
//==============================================================================


//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================
void LCD_voidInit(void);

void LCD_voidSendCommand(uint8_t copy_u8Command);

void LCD_voidDisplayCharacter(uint8_t copy_u8Data);

void LCD_voidDisplayString(const char *copy_u8Str);

void LCD_voidIntegerToString(uint32_t copy_u32Data);

void LCD_voidPrintFloat(float copy_f32Value, uint8_t copy_u8DecimalPlaces);

void LCD_voidDisplayStringRowColumn(uint8_t copy_u8Row, uint8_t copy_u8Col, const char *copy_u8Str);

void LCD_voidDefineCustomChar(uint8_t copy_u8Location, const uint8_t copy_u8CharMap[8]);

E_Status LCD_xGoTo(uint8_t copy_u8Row, uint8_t copy_u8Col);

void LCD_voidClearScreen(void);

#endif /* __LCD_INTERFACE_H__ */