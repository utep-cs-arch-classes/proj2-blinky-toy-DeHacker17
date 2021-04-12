#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static short a_note = 440;
static short b_note = 494;
static short c_note = 523;
static short d_note = 587;
static short e_note = 659;
static short f_note = 698;
static short g_note = 784;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void mySong() {
  char oldMcdonald[] = "cgagedcgcgagedcgcgcgagedc";
  char temp;
  static int i = 0;
  temp = oldMcdonald[i];
  switch(temp) {
  case 'a':
    buzzer_set_period(a_note);
    break;
  case 'b':
    buzzer_set_period(b_note);
    break;
  case 'c':
    buzzer_set_period(c_note);
    break;
  case 'd':
    buzzer_set_period(d_note);
    break;
  case 'e':
    buzzer_set_period(e_note);
    break;
  case 'f':
    buzzer_set_period(f_note);
    break;
  case 'g':
    buzzer_set_period(g_note);
    break;
  }
  i++;
  if (i == sizeof(oldMcdonald) - 1) {
    i = 0;
  }
}
