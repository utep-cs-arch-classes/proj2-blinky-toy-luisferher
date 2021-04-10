#ifndef switches_included
#define switches_included

#define SW0 BIT0   /* switch0 is p2.0 */
#define SW1 BIT1
#define SW2 BIT2
#define SW3 BIT3

#define SWITCHES (BIT0 | BIT1 | BIT2 | BIT3)		/* 4 switches on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed, b_state; /* effectively boolean */

#endif // included
