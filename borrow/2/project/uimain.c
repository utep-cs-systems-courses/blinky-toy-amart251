#include <msp430.h>
#include "h/libTimer.h"
#include "buzzer.h"

#define BSW1 BIT3
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define BSWITCHES BSW1
#define SWITCHES (SW1 | SW2 | SW3 | SW4)

int main() {
    configureClocks();

    P1REN |= BSWITCHES;
    P1IE |= BSWITCHES;
    P1OUT |= BSWITCHES;
    P1DIR &= ~BSWITCHES;

    P2REN |= SWITCHES;
    P2IE |= SWITCHES;
    P2OUT |= SWITCHES;
    P2DIR &= ~SWITCHES;
      
    buzzer_init();
    // buzzer_set_period(1000);	/* start buzzing!!! 2MHz/1000 = 2kHz*/

    configureClocks();
    enableWDTInterrupts();

    or_sr(0x18);          // CPU off, GIE on
}

void
switch_interrupt_handler() {
  char p1val = P1IN;
  char p2val = P2IN;
  //buzzer_init();
  P1IES |= (p1val & BSWITCHES);
  P1IES &= (p1val | ~BSWITCHES);

  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  
  if(!(p1val & BSW1)) {
    buzzer_set_period(1000);
  }
  else if(!(p2val & SW1)) {
    buzzer_set_period(10000);
  }
  else if (!(p2val & SW2)) {
    buzzer_set_period(5000);
  }
  else if (!(p2val & SW3)) {
    buzzer_set_period(2500);
  }
  else if (!(p2val & SW4)) {
    buzzer_set_period(1250);
  }
  else {
    buzzer_set_period(0);
  }
}

void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & BSWITCHES) {
    P1IFG &= ~BSWITCHES;
    switch_interrupt_handler();
  }
}

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

int secondCount = 0;

void __interrupt_vec(WDT_VECTOR) WDT()
{
  secondCount ++;
  if (secondCount >= 250) {
    secondCount = 0;
    buzzer_set_period(0);
  }
}
