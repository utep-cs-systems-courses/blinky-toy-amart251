#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char count = 0;
  count++;
  if ((count % 31)==0) {   // 1/8 count 
    state_advance();
    count = 0;
  }
  /*
  else if ((count % 15)==0 && sw_state == 2) {   // 1/8 count 
    state_advance();
    count = 0;
  }
  else if ((count % 62)==0 && sw_state == 3) {   // 1/8 count 
    state_advance();
    count = 0;
    }*/
}
