#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

#define SW1 BIT0    /* switch1 is p2.0 */
#define SW2 BIT1    /* switch2 is p2.1 */
#define SW3 BIT2    /* switch3 is p2.2 */
#define SW4 BIT3    /* switch4 is p2.3 */

#define SWITCHES (SW1|SW2|SW3|SW4)   /* all switches on this board */

void main(void) 
{  
  configureClocks();

  P2REN |= SWITCHES;        /* enables resistors for switches */
  P2IE |= SWITCHES;         /* enable interrupts from switches */
  P2OUT |= SWITCHES;        /* pull-ups for switches */
  P2DIR &= ~SWITCHES;       /* set switches' bits for input */

  or_sr(0x18);  // CPU off, GIE on
} 

void
switch_interrupt_handler()
{
  char p2val = P2IN;         /* switches are in P2 */

/* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);     /* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);    /* if switch down, sense up */

/* play different sound according to the button pressed */
  if (p2val & SW1) {
    buzzer_set_period(1000);	/* 2MHz/1000 = 2kHz */
  } else if (p2val & SW2) {
    buzzer_set_period(2000);	/* 2MHz/2000 = 1kHz */
  } else if (p2val & SW3) {
    buzzer_set_period(3000);	/* 2MHz/3000 ~= 666Hz */
  } else if (p2val & SW4) {
    buzzer_set_period(4000);	/* 2MHz/4000 = 500Hz */
  }
}

/* Switch on P2 */
void
__interrupt_vec(PORT2_VECTOR) Port_1(){
  if (P2IFG & SWITCHES) {            /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;              /* clear pending sw interrupts */
    switch_interrupt_handler();      /* single handler for all switches */
  }
}

int main() {
    configureClocks();
 
    buzzer_init();
    buzzer_set_period(1000);	/* start buzzing!!! 2MHz/1000 = 2kHz*/

    or_sr(0x18);          // CPU off, GIE on
}
