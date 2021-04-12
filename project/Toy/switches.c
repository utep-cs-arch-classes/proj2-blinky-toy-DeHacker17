#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "libTimer.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char
upswitches_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & UPSWITCHES);
  P2IES &= (p2val | ~UPSWITCHES);
  return p2val;
}

void 
switch_init()
{
  P2REN |= UPSWITCHES;
  P2IE |= UPSWITCHES;
  P2OUT |= UPSWITCHES;
  P2DIR &= UPSWITCHES;
  upswitches_update_interrupt_sense();
  led_update();
} 

void
upswitches_interrupt_handler()
{
  char p2val = upswitches_update_interrupt_sense();
  //switch_state_down = (p2val & SW0) ? 0 : 1; /* 0 when SW1 is up */
  if ((p2val & SW0) && (p2val & SW1) && (p2val & SW2) && (p2val & SW3)) {
    buzzer_set_period(0);
    switch_state_down = 0;
  }
  else if (p2val & SW0) {
    switch_state_down = 1;
    led_update();
  }
  else if (p2val & SW1) {
    enableWDTInterrupts();
    switch_state_down = 1;
  }
  switch_state_changed = 1
}
