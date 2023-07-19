
#ifndef MAIN_H
#define MAIN_H

#include <msp430.h>

// Button definitions
#define SW1 BIT0    /* switch1 is p2.0 */
#define SW2 BIT1    /* switch2 is p2.1 */
#define SW3 BIT2    /* switch3 is p2.2 */
#define SW4 BIT3    /* switch4 is p2.3 */

#define SWITCHES (SW1|SW2|SW3|SW4)   /* all switches on this board */

// Function declarations
void main(void);
void switch_interrupt_handler(void);
void __interrupt_vec(PORT2_VECTOR) Port_1();

#endif // MAIN_H
