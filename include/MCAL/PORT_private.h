/**
 * @file    PORT_private.h
 * @author  Mohamed Moaaz
 * @brief   PORT private file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __PORT_PRIVATE_H__
#define __PORT_PRIVATE_H__

//==============================================================================
// Macros & Defines
//==============================================================================

/*for pin direction*/
#define INPUT      0
#define OUTPUT     1

/*for pin value*/
#define FLOATING   0
#define LOW        0
#define IN_PULL_UP 1
#define HIGH       1

#define CONC(b7, b6, b5, b4, b3, b2, b1, b0)            CONC_HELPER(b7, b6, b5, b4, b3, b2, b1, b0)
#define CONC_HELPER(b7, b6, b5, b4, b3, b2, b1, b0)     0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIR               CONC(PORTA_PIN7_DIR, PORTA_PIN6_DIR, PORTA_PIN5_DIR, PORTA_PIN4_DIR, PORTA_PIN3_DIR, PORTA_PIN2_DIR, PORTA_PIN1_DIR, PORTA_PIN0_DIR)
#define PORTB_DIR               CONC(PORTB_PIN7_DIR, PORTB_PIN6_DIR, PORTB_PIN5_DIR, PORTB_PIN4_DIR, PORTB_PIN3_DIR, PORTB_PIN2_DIR, PORTB_PIN1_DIR, PORTB_PIN0_DIR)
#define PORTC_DIR               CONC(PORTC_PIN7_DIR, PORTC_PIN6_DIR, PORTC_PIN5_DIR, PORTC_PIN4_DIR, PORTC_PIN3_DIR, PORTC_PIN2_DIR, PORTC_PIN1_DIR, PORTC_PIN0_DIR)
#define PORTD_DIR               CONC(PORTD_PIN7_DIR, PORTD_PIN6_DIR, PORTD_PIN5_DIR, PORTD_PIN4_DIR, PORTD_PIN3_DIR, PORTD_PIN2_DIR, PORTD_PIN1_DIR, PORTD_PIN0_DIR)

#define PORTA_INITIAL_VALUE     CONC(PORTA_PIN7_INITIAL_VALUE, PORTA_PIN6_INITIAL_VALUE, PORTA_PIN5_INITIAL_VALUE, PORTA_PIN4_INITIAL_VALUE, PORTA_PIN3_INITIAL_VALUE, PORTA_PIN2_INITIAL_VALUE, PORTA_PIN1_INITIAL_VALUE, PORTA_PIN0_INITIAL_VALUE)
#define PORTB_INITIAL_VALUE     CONC(PORTB_PIN7_INITIAL_VALUE, PORTB_PIN6_INITIAL_VALUE, PORTB_PIN5_INITIAL_VALUE, PORTB_PIN4_INITIAL_VALUE, PORTB_PIN3_INITIAL_VALUE, PORTB_PIN2_INITIAL_VALUE, PORTB_PIN1_INITIAL_VALUE, PORTB_PIN0_INITIAL_VALUE)
#define PORTC_INITIAL_VALUE     CONC(PORTC_PIN7_INITIAL_VALUE, PORTC_PIN6_INITIAL_VALUE, PORTC_PIN5_INITIAL_VALUE, PORTC_PIN4_INITIAL_VALUE, PORTC_PIN3_INITIAL_VALUE, PORTC_PIN2_INITIAL_VALUE, PORTC_PIN1_INITIAL_VALUE, PORTC_PIN0_INITIAL_VALUE)
#define PORTD_INITIAL_VALUE     CONC(PORTD_PIN7_INITIAL_VALUE, PORTD_PIN6_INITIAL_VALUE, PORTD_PIN5_INITIAL_VALUE, PORTD_PIN4_INITIAL_VALUE, PORTD_PIN3_INITIAL_VALUE, PORTD_PIN2_INITIAL_VALUE, PORTD_PIN1_INITIAL_VALUE, PORTD_PIN0_INITIAL_VALUE)

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __PORT_PRIVATE_H__ */