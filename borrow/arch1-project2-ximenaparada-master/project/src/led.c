#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
unsigned char green_led_state = 0;
unsigned char red_led_state = 0;

//static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_update();
}

void led_update() {
  if(green_led_state) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
  if(red_led_state) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}

void led_red_on(int on)
{
  if(on) P1OUT |= LED_RED;
  else P1OUT &= ~LED_RED;
}

void led_green_on(int on)
{
  if (on) P1OUT |= LED_GREEN;
  else P1OUT &= ~LED_RED;
}
