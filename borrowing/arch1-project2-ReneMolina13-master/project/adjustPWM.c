#include <msp430.h>
#include "led.h"
#include "toyCtrl.h"
#include "adjustPWM.h"

void increaseRed(void)
{
  if (dutyCycleRed >= LED_PWM_PERIOD)
    dutyCycleRed = LED_PWM_PERIOD;
  else
    dutyCycleRed++;
}

void increaseGreen(void)
{
  if (dutyCycleGreen >= LED_PWM_PERIOD)
    dutyCycleGreen = LED_PWM_PERIOD;
  else
    dutyCycleGreen++;
}

void decreaseRed(void)
{
  if (dutyCycleRed <= 0)
    dutyCycleRed = 0;
  else
    dutyCycleGreen --;
}

void decreaseGreen(void)
{
  if (dutyCycleGreen <= 0)
    dutyCycleGreen = 0;
  else
    dutyCycleGreen--;
}

void buzzerMax(void)
{
  TACCR1 = BUZZER_PWM_PERIOD;
}

void buzzerIncrease(void)
{
  if (dutyCycleBuzzer >= 0.9)
    dutyCycleBuzzer = 1.0;
  else
    dutyCycleBuzzer += 0.1;
  TACCR1 = (int) (dutyCycleBuzzer * BUZZER_PWM_PERIOD);
}

void buzzerZero(void)
{
  TACCR1 = 0;
}

void buzzerDecrease(void)
{
  if (dutyCycleBuzzer <= 0.1)
    dutyCycleBuzzer = 0;
  else
    dutyCycleBuzzer -= 0.1;
  TACCR1 = (int) (dutyCycleBuzzer * BUZZER_PWM_PERIOD);
}
