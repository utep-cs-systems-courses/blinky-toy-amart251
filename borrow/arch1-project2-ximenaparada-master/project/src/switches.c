#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

char switch_state_down, switch_state_down;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if (~p2val & SW1) {
    sw_state = 1;
  }
  else if (~p2val & SW2) {
    sw_state = 2;
  }
  else if (~p2val & SW3) {
    sw_state = 3;
  }
  else if (~p2val & SW4) {
    sw_state = 4;
  }
  /* 0 when SW1 is up */
 
  else {
    sw_state = 4;
  }
  // sw1, sw2, sw3, sw4
}
