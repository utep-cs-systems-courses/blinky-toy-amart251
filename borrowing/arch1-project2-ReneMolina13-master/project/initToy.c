#include <msp430.h>
#include "led.h"
#include "initToy.h"
#include "toyCtrl.h"

void initToy(void)
{
  initClocks();
  initLEDs();
  initButtons();
  initBuzzer();
}

void initClocks(void)
{
  WDTCTL = WDTPW | WDTHOLD; // disable WDT
  BCSCTL1 = CALBC1_16MHZ;   // set DCO to 16 MHz
  DCOCTL = CALDCO_16MHZ;

  BCSCTL2 &= ~SELS;         // SMCLK source = DCO
  BCSCTL2 |= DIVS_3;        // SMCLK = DC0/8 (2 MHz)
}

void initLEDs(void)
{
  // setup LEDs for GPIO output
  P1SEL &= ~LED_BOTH;
  P1SEL2 &= ~LED_BOTH;
  P1DIR |= LED_BOTH;
  P1OUT |= LED_BOTH; // turn LEDs on

  // turn on WDT, setup for timer mode, clear count
  WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | 1; // setup for 250 interrupts/sec
  IE1 |= WDTIE;
  wdtCountRed = 0;
  wdtCountGreen = 0;

  // setup PWM duty cycle to 50% for both LEDs
  dutyCycleRed = 5;
  dutyCycleGreen = 5;
}

void initButtons(void)
{
  // buttons in GPIO input with pull-up resistors
  P2SEL &= ~BUTTONS;
  P2SEL2 &= ~BUTTONS;
  P2DIR &= ~BUTTONS;
  P2REN |= BUTTONS;
  P2OUT |= BUTTONS;
  P2IES |= BUTTONS;  // interrupt on high-to-low transition
  P2IE |= BUTTONS;   // enable interrupts
  P2IFG &= ~BUTTONS; // reset interrupt flags
}

void initBuzzer(void)
{
  // setup buzzer for PWM
  P2SEL |= BUZZER;
  P2SEL &= ~BIT7;
  P2SEL2 &= ~(BUZZER | BIT7);
  P2DIR |= BUZZER;
  P2DIR &= ~BIT7;

  // setup Timer A for up mode with clock source = SMCLK
  TACTL = TASSEL_2 | MC_1;    // no interrupts or clock division
  TACCTL0 = OUTMOD_7;         // reset/set mode, no interrupts, compare mode
  TACCR0 = BUZZER_PWM_PERIOD; // set CCR0 for a PWM period for 1,000 cycles (0.5 ms)
  dutyCycleBuzzer = 1;        // set duty cycle to 100%
  TACCR1 = (int) (dutyCycleBuzzer * BUZZER_PWM_PERIOD); // set CCR1 for a duty cycle of 50%
}
