#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "stateMachines.h"
#include "switches.h"
#include "libTimer.h"

char switch_state_down, switch_state_changed, songTimer; /* effectively boolean */

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
  P2IE = UPSWITCHES;
  P2OUT |= UPSWITCHES;
  P2DIR &= ~UPSWITCHES;
}

void
upswitches_interrupt_handler()
{
  char p2val = upswitches_update_interrupt_sense();
  if ((p2val & SW1) && (p2val & SW2) && (p2val & SW3) && (p2val & SW4)){
    buzzer_set_period(0);
    switch_state_down = 0;
  }
  else if (!(p2val & SW1)) {
    //enableWDTInterrupts();
    switch_state_down = 1;
    songTimer = 125;
    mySong();
    led_update();
  }
  else if (!(p2val & SW2)) {
    //enableWDTInterrupts();
    switch_state_down = 1;
    songTimer = 40;
    mySong2();
    state_advance();
  }
  else if (!(p2val & SW4)) {
    //enableWDTInterrupts();
    switch_state_down = 1;
    songTimer = 60;
    mySong4();
    led_update();
  }
  if (!(p2val & SW3)) {
    switch_state_down = 1;
    songTimer = 20;
    mySong3();
    state_advance();
    led_update();
  }
  state_advance();
  switch_state_changed = 1;
}
