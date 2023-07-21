//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  //P1OUT &= ~LED_GREEN;
  //P1OUT |= LED_RED;
  
  P1OUT |= LED_GREEN;          //line 1
  //P1OUT |= LED_RED;            //line 2
  P1OUT &= ~LED_RED;         //line 3
  //P1OUT &= ~LED_GREEN;       //line 4

  //to turn off both leds have lines 3 and 4
  //to turn on green only have lines 1 and 3
  //to turn on red only have lines 2 and 4
  
  or_sr(0x18);		/* CPU off, GIE on */
}
