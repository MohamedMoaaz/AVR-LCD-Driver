/**
 * @file    LCD_configuration.h
 * @author  Mohamed Moaaz
 * @brief   LCD configuration file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __LCD_CONFIGURATION_H__
#define __LCD_CONFIGURATION_H__

#include "MCAL/DIO_register.h"
//==============================================================================
// Macros & Defines
//==============================================================================

/*select the PORT of each PIN
                        options :
                        1-DIO_u8PORTA
                        2-DIO_u8PORTB
                        3-DIO_u8PORTC
                        4-DIO_u8PORTD
                        */
/*PIN PORTS*/
#define EN_PORT         DIO_u8PORTA
#define RS_PORT         DIO_u8PORTA
#define D4_PORT         DIO_u8PORTA
#define D5_PORT         DIO_u8PORTA
#define D6_PORT         DIO_u8PORTA
#define D7_PORT         DIO_u8PORTA

/*select control and data PINS
*options : 1->8 */
/*Control PINs*/
#define EN_PIN          4
#define RS_PIN          5
/*Data PINS*/
#define D4_PIN          0
#define D5_PIN          1
#define D6_PIN          2
#define D7_PIN          3

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __LCD_CONFIGURATION_H__ */