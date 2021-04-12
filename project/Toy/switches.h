#ifndef switches_included
#define switches_included

//#define SW4 BIT3		/* switch1 is p1.3 */
#define SW0 BIT0
#define SW1 BIT1    // Use P2 for EduKit
#define SW2 BIT2
#define SW3 BIT3
//#define SWITCH SW4
#define UPSWITCHES (SW0 | SW1 | SW2 | SW3)

void switch_init();
void upswitches_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
