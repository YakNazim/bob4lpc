
/*
 * bob4.h
 */

#ifndef _BOB4_H
#define _BOB4_H


/*
 *   Emacs note: ctrl-q <char> quoted-insert
 *   vim note:   ctl-v <char> 
 */

/* control string definitions for bob4 */

/*
 * These ascii string commands come from
 * BOB-4H & BOB-4S Application Guide
 */

#define FONT_SET_8X13            "[1z"
#define FONT_SET_6X10            "[4z"

#define CLEAR_ATTRIBUTES         "[0m"
#define CLEAR_SCREEN             "[2J"

#define START_CRAWL              "[1;180;1;70t"
#define STOP_CRAWL              "[0t"


#define MOVE_CURSOR_RIGHT_ONE    "[1C"
#define MOVE_CURSOR_RIGHT_TEN    "[10C"
#define MOVE_CURSOR_RIGHT_TWENTY "[20C"

#define MOVE_CURSOR_DOWN_ONE     "[1B"
#define MOVE_CURSOR_DOWN_FIVE    "[5B"

#define MOVE_UPPER_LEFT          "[0;0H"
#define MOVE_UPPER_RIGHT         "[5H[40C"

#define REPORT_CURSOR_POSITION   "[6n"

/*
#define MOVE_CURSOR_UP_ONE       [1A
#define MOVE_CURSOR_UP_FIVE      [5A 

#define MOVE_CURSOR_RIGHT_ONE    [1C
#define MOVE_CURSOR_RIGHT_FIVE   [5C 

#define MOVE_CURSOR_LEFT_ONE     [1D
#define MOVE_CURSOR_LEFT_FIVE    [5D 

#define MOVE_UPPER_LEFT          [5H
#define MOVE_UPPER_RIGHT         [50;0H[10C
*/




/*
 * initialize
 * -----------------------------------------------
 * initialize the lpc2148 pll 
 * cpu interrupts
 * the uart0 serial port
 * the rtc VIC interrupt
 */
void initialize(void);



void TIMER0_Handler (void)   __attribute__ ((interrupt("IRQ")));



void IRQ_Routine (void)   __attribute__ ((interrupt("IRQ")));
void FIQ_Routine (void)   __attribute__ ((interrupt("FIQ")));
void SWI_Routine (void)   __attribute__ ((interrupt("SWI")));
void UNDEF_Routine (void) __attribute__ ((interrupt("UNDEF")));


#endif
