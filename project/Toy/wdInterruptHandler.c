#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == songTimer) {
    blink_count = 0;
    //state_advance(); // Makes blink pattern
    upswitches_interrupt_handler(); // Awesome songs with all 4 buttons
  }
  //upswitches_interrupt_handler(); // Weird sounds
  //state_advance();  // Red will blink ultra fast
}
