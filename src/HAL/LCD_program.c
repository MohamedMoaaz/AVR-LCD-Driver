/**
 * @file    LCD.c
 * @author  Mohamed Moaaz
 * @brief   LCD program file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "STD_TYPES.h"
#include "MCAL/DIO_interface.h"
#include "HAL/LCD_Private.h"
#include "HAL/LCD_Interface.h"
#include "HAL/LCD_configuration.h"

//==============================================================================
// Extern Variables
//==============================================================================

//==============================================================================
// Private Macros & Defines
//==============================================================================

//==============================================================================
// Private Typedefs
//==============================================================================

//==============================================================================
// Static Variables
//==============================================================================

//==============================================================================
// Global Variables
//==============================================================================

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Static Functions Prototypes
//==============================================================================

//==============================================================================
// Static Functions
//==============================================================================

//==============================================================================
// Global Functions
//==============================================================================

void LCD_voidInit(void)
{
    _delay_ms(40);
    LCD_voidSendCommand(_LCD_RETURN_HOME);
    LCD_voidSendCommand(_LCD_4BIT_MODE_2_LINE);
    _delay_ms(5);
    LCD_voidSendCommand(_LCD_4BIT_MODE_2_LINE);
    _delay_ms(1);
    LCD_voidSendCommand(_LCD_4BIT_MODE_2_LINE);
    LCD_voidSendCommand(_LCD_ENTRY_MODE_INC_SHIFT_OFF);
    LCD_voidSendCommand(_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
    _delay_ms(1);
}

void LCD_voidSendCommand(uint8_t copy_u8Command)
{
    RS(LCD_CMD);
    _delay_ms(1);
    D7(GET_BIT(copy_u8Command, 7));
    D6(GET_BIT(copy_u8Command, 6));
    D5(GET_BIT(copy_u8Command, 5));
    D4(GET_BIT(copy_u8Command, 4));

    EN(DIO_u8PIN_HIGH);
    _delay_ms(1);
    EN(DIO_u8PIN_LOW);
    _delay_ms(1);

    D7(GET_BIT(copy_u8Command, 3));
    D6(GET_BIT(copy_u8Command, 2));
    D5(GET_BIT(copy_u8Command, 1));
    D4(GET_BIT(copy_u8Command, 0));

    EN(DIO_u8PIN_HIGH);
    _delay_ms(1);
    EN(DIO_u8PIN_LOW);
    _delay_ms(1);
}

void LCD_voidDisplayCharacter(uint8_t copy_u8Data)
{
    RS(LCD_DATA);
    _delay_ms(1);
    D7(GET_BIT(copy_u8Data, 7));
    D6(GET_BIT(copy_u8Data, 6));
    D5(GET_BIT(copy_u8Data, 5));
    D4(GET_BIT(copy_u8Data, 4));

    EN(DIO_u8PIN_HIGH);
    _delay_ms(1);
    EN(DIO_u8PIN_LOW);
    _delay_ms(1);

    D7(GET_BIT(copy_u8Data, 3));
    D6(GET_BIT(copy_u8Data, 2));
    D5(GET_BIT(copy_u8Data, 1));
    D4(GET_BIT(copy_u8Data, 0));

    EN(DIO_u8PIN_HIGH);
    _delay_ms(1);
    EN(DIO_u8PIN_LOW);
    _delay_ms(1);
}

void LCD_voidDisplayString(const char *copy_u8Str)
{
    uint8_t Local_u8Iterator = 0;
    while (copy_u8Str[Local_u8Iterator] != '\0')
    {
        LCD_voidDisplayCharacter(copy_u8Str[Local_u8Iterator]);
        Local_u8Iterator++;
    }
}

void LCD_voidIntegerToString(uint32_t copy_u32Data)
{
    uint8_t Local_u8Buff[16];
    itoa(copy_u32Data, Local_u8Buff, 10);
    LCD_voidDisplayString(Local_u8Buff);
}

void LCD_voidPrintFloat(float copy_f32Value, uint8_t copy_u8DecimalPlaces)
{
    char Local_u8Buffer[16]; // Adjust the buffer size as needed
    snprintf(Local_u8Buffer, sizeof(Local_u8Buffer), "%.*f", copy_u8DecimalPlaces, copy_f32Value);
    LCD_voidDisplayString(Local_u8Buffer);
}

void LCD_voidDisplayStringRowColumn(uint8_t copy_u8Row, uint8_t copy_u8Col, const char *copy_u8Str)
{
    LCD_xGoTo(copy_u8Row, copy_u8Col);
    LCD_voidDisplayString(copy_u8Str);
}

void LCD_voidDefineCustomChar(uint8_t copy_u8Location, const uint8_t copy_u8CharMap[8])
{
    LCD_voidSendCommand(_LCD_CGRAM_START + (copy_u8Location * 8));
    for (uint8_t i = 0; i < 8; i++)
    {
        LCD_voidDisplayCharacter(copy_u8CharMap[i]);
    }
}

E_Status LCD_xGoTo(uint8_t copy_u8Row, uint8_t copy_u8Col)
{
    E_Status E_State = E_OK;
    uint8_t Local_u8Address;
    if (copy_u8Col <= 39)
    {
        switch (copy_u8Row)
        {
        case 1:
            Local_u8Address = copy_u8Col;
            break;
        case 2:
            Local_u8Address = copy_u8Col + 0x40;
            break;
        case 3:
            Local_u8Address = copy_u8Col + 0x10;
            break;
        case 4:
            Local_u8Address = copy_u8Col + 0x50;
            break;
        default:
            E_State = E_NOK;
            break;
        }
    }
    else
        E_State = E_NOK;
    LCD_voidSendCommand(Local_u8Address | (_LCD_DDRAM_START));
    return E_State;
}

void LCD_voidClearScreen(void)
{
    LCD_voidSendCommand(_LCD_CLEAR);
}