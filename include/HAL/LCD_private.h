/**
 * @file    LCD_private.h
 * @author  Mohamed Moaaz
 * @brief   LCD private file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __LCD_PRIVATE_H__
#define __LCD_PRIVATE_H__

//==============================================================================
// Macros & Defines
//==============================================================================

#define _LCD_CLEAR                                  0X01
#define _LCD_RETURN_HOME                            0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF               0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON                0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF               0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON                0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT                 0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT                0x14
#define _LCD_DISPLAY_SHIFT_LEFT                     0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                    0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF    0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON     0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF     0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON      0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF                 0x08
#define _LCD_8BIT_MODE_2_LINE                       0x38
#define _LCD_4BIT_MODE_2_LINE                       0x28

#define _LCD_CGRAM_START                            0x40
#define _LCD_DDRAM_START                            0x80

#define LCD_CMD    0
#define LCD_DATA   1


#define D4(x) DIO_u8SetPinValue(D4_PORT, D4_PIN, x)
#define D5(x) DIO_u8SetPinValue(D5_PORT, D5_PIN, x)
#define D6(x) DIO_u8SetPinValue(D6_PORT, D6_PIN, x)
#define D7(x) DIO_u8SetPinValue(D7_PORT, D7_PIN, x)
#define EN(x) DIO_u8SetPinValue(EN_PORT, EN_PIN, x)
#define RS(x) DIO_u8SetPinValue(RS_PORT, RS_PIN, x)

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __LCD_PRIVATE_H__ */