#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "toyCtrl.h"
#include "initToy.h"

int main(void)
{
  and_sr(0x08);  // disable maskable interrupts
  initToy();     // initialize peripherals
  while (1)
    or_sr(0x18); // CPU off, Geneeral Interrupt Enable (GIE) on
}

void button_interrupt_handler()
{
  switch (currentInterrupt) {
  case BUTTON_0:
    adjustRed(RED_INCREASE);
    adjustBuzzer(BUZZER_MAX);
    break;
  case BUTTON_1:
    adjustGreen(GREEN_INCREASE);
    adjustBuzzer(BUZZER_INCREASE);
    break;
  case BUTTON_2:
    adjustRed(RED_DECREASE);
    adjustBuzzer(BUZZER_DECREASE);
    break;
  case BUTTON_3:
    adjustGreen(GREEN_DECREASE);
    adjustBuzzer(BUZZER_ZERO);
  }
}

void __interrupt_vec(PORT2_VECTOR) Port_2()
{
  currentInterrupt = P2IFG;
  P2IFG = 0;
  
  if (currentInterrupt & BUTTONS)
    button_interrupt_handler();
}

// handles PWM for LEDs (250 interrups/sec)
void __interrupt_vec(WDT_VECTOR) WDT()
{
  wdtCountRed++;
  if (wdtCountRed == dutyCycleRed) {
    P1OUT ^= LED_RED;
  }
  if (wdtCountRed >= LED_PWM_PERIOD) {
    P1OUT ^= LED_RED;
    wdtCountRed = 0;
  }

  wdtCountGreen++;
  if (wdtCountGreen == dutyCycleGreen)
    P1OUT ^= LED_GREEN;
  if (wdtCountGreen >= LED_PWM_PERIOD) {
    P1OUT ^= LED_GREEN;
    wdtCountGreen = 0;
  }
}
