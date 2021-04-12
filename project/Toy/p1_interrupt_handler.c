#include <msp430.h>
#include "switches.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & UPSWITCHES) {
    P2IFG &= ~UPSWITCHES;
    upswitches_interrupt_handler();
  }
}



