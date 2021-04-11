#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

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
void green_always_on(){
    green_on = 1;
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
    red_on = 0;
    state = 3;
    break;
  case 3:
    red_on = 1;
    state = 0;
    break;
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
    red_on = 1;
    state = 3;
    break;
  case 3:
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
    buzzer_set_period(2251);
    break;
  case 1:
    red_on = 0;
    green_on = 0;
    state = 0;
    buzzer_set_period(0);
    break;
}
  led_changed = changed;
  led_update();
}

void dimmingRed(){
  switch(state_dim){
  case 0:
    toggle_red25();
    break;
  case 1:
    toggle_red75();
    break;
  }
}
void dimmingGreen(){
  switch(state_dim){
  case 0:
    toggle_green();
    break;
  case 1:
    green_always_on();
    break;
  }
}
void change_dimming(){
  if(state_dim == 0){
    state_dim = 1;
  }
  else{
    state_dim = 0;
  }
}
void song(){
  static char state = 0;
  switch(state){
  case 0:
    buzzer_set_period(2863);
    state = 1;
    break;
  case 1:
    buzzer_set_period(0);
    state = 2;
    break;
  case 2:
    buzzer_set_period(3405);
    state = 3;
    break;
  case 3:
    buzzer_set_period(0);
    state = 0;
    break;
  }
}
