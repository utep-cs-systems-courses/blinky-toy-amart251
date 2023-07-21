#include <msp430.h>
#include "toyCtrl.h"
#include "adjustPWM.h"

void adjustBuzzer(int direction)
{
  switch (direction) {
  case BUZZER_MAX:
    buzzerMax();
    break;
  case BUZZER_INCREASE:
    buzzerIncrease();
    break;
  case BUZZER_DECREASE:
    buzzerDecrease();
    break;
  case BUZZER_ZERO:
    buzzerZero();
  }
}
