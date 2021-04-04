#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char state_dim = 0;
void toggle_red()		/*Turn red on and off */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}

void toggle_green()	/* turn green on and off */
{
  static char state = 0;
  switch(state){
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
void red_always_on(){
    red_on = 1;
    led_changed = 1;
    led_update();
}
void toggle_red25(){
  static char state = 0;
  switch(state){
  case 0:
    red_on = 0;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 2;
    break;
  case 2:
    red_on = 1;
    state = 0;
  }
  led_changed = 1;
  led_update();
}
void toggle_red75(){
  static char state = 0;
  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    state = 2;
    break;
  case 2:
    red_on = 0;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
void simple_state(){ /* alternate between red & green on at the same time and off*/
  static char state = 0;
  char changed = 1; 
  switch(state) {
  case 0:
    red_on = 1;
    green_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    green_on = 0;
    state = 0;
    break;
}
  led_changed = changed;
  led_update();
}

void dimming(){
  switch(state_dim){
  case 0:
    toggle_red25();
    break;
  case 1:
    toggle_red();
    break;
  case 2:
    toggle_red75();
    break;
  }
}
void change_dimming(){
  if(state_dim == 0){
    state_dim = 1;
  }
  else if(state_dim == 1){
    state_dim = 2;
  }
  else{
    state_dim = 0;
  }
}
