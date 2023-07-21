#include <msp430.h>
#include "led.h"
#include "toyCtrl.h"
#include "adjustPWM.h"

void adjustRed(int direction)
{  
  switch (direction) {
  case RED_INCREASE:
    increaseRed();
    break;
  case RED_DECREASE:
    decreaseRed();
  }
}

void adjustGreen(int direction)
{
  switch (direction) {
  case GREEN_INCREASE:
    increaseGreen();
    break;
  case GREEN_DECREASE:
    decreaseGreen();
  }
}
