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

static short upa_note = 880;
static short upb_note = 988;
static short upc_note = 1047;
static short upd_note = 1175;
static short upe_note = 1319;
static short upf_note = 1397;
static short upg_note = 1568;

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

void mySong2() {
  char ILoveYou[] = "gegegagfedefefgcdefgdfedc";
  char temp;
  static int j = 0;
  temp = ILoveYou[j];
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
  j++;
  if (j == sizeof(ILoveYou) - 1) {
    j = 0;
  }
}

void mySong3() {
  char JingleBells[] = "egcdefededgegcdefegfdc";
  char temp;
  static int k = 0;
  temp = JingleBells[k];
  switch(temp) {
  case 'a':
    buzzer_set_period(upa_note);
    break;
  case 'b':
    buzzer_set_period(upb_note);
    break;
  case 'c':
    buzzer_set_period(upc_note);
    break;
  case 'd':
    buzzer_set_period(upd_note);
    break;
  case 'e':
    buzzer_set_period(upe_note);
    break;
  case 'f':
    buzzer_set_period(upf_note);
    break;
  case 'g':
    buzzer_set_period(upg_note);
    break;
  }
  k++;
  if (k == sizeof(JingleBells) - 1) {
    k = 0;
  }
}

void mySong4() {
  char TwinkleStar[] = "gdedcbagdcbadcbagdedcbag";
  char temp;
  static int l = 0;
  temp = TwinkleStar[l];
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
  l++;
  if (l == sizeof(TwinkleStar) - 1) {
    l = 0;
  }
} 
