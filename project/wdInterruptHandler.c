#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char b_state = 0;
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static int state_count = 0;
  if(++blink_count == 125 && b_state == 0){
    song();
    blink_count = 0;
  }
  else if (blink_count == 125 && b_state == 1) {
    simple_state();
    blink_count = 0;
  }
  else if(blink_count == 2 && b_state == 2){
    dimmingRed();
    blink_count = 0;
 if(++state_count == 325){
    change_dimming();
    state_count = 0;
 }
  }
 else if(blink_count == 2 && b_state == 3){
   dimmingGreen();
   blink_count = 0;
   if(++state_count == 200){
     change_dimming();
     state_count = 0;
   }
 }
}
