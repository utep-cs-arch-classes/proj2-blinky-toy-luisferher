#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static int state_count = 0;
  if (++blink_count == 125) {
    //dimming();
    simple_state();
    blink_count = 0;
  }
  if(++state_count == 325){
    //change_dimming();
    state_count = 0;
  }
}
