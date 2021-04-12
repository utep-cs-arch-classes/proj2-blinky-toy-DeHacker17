#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char song_count = 0;
  if (++blink_count == 30) {
    state_advance();
    blink_count = 0;
    } 
  if (++song_count == 40) {
    mySong();
  }
}
