
/*
 * bob4.c
 */

#include <string.h>


#include "./include/bob4.h"

#include "types.h"
#include "lpc214x.h"
#include "pll.h"
#include "olimex.h"
#include "interrupts.h"
#include "lpc-serial.h"
#include "lpc-timer.h"
#include "helpers.h"

#include "bob4.h"

#define BUFFSIZE 10
#define MAXTIMER 1000000000
/* Emacs note: ctrl-q ESC. 'quoted-insert'
   vim note:   ctl-v char */



/*


  Q
  [2J[6zPSAS[1z
  Portland State Aerospace Society
  [170;100.r[35;0;360)r[1#r
  [170;100.r[35;0;360)r[3/r
  [145;100.r[10;0;360)r[0#r
  [135;65.r[135;135-r[/r
  [100;100.r[170;100-r[/r
  [1z[15;15H[5mhttp://psas.pdx.edu[0mR[8v[1v




*/

char* PSAS_test="Q[2J[6zPSAS[1zPortland State Aerospace Society[170;100.r[35;0;360)r[1#r[170;100.r[35;0;360)r[3/r[145;100.r[10;0;360)r[0#r[135;65.r[135;135-r[/r[100;100.r[170;100-r[/r[1z[15;15H[5mhttp://psas.pdx.edu[0mR[8v[1v";

int main() {
    unsigned int i;

    unsigned int timer0_val = 0;
    unsigned int timer1_val = 0;

    // Initialize the system
    initialize();

    serial_putstring(CLEAR_ATTRIBUTES);
    serial_putstring(CLEAR_SCREEN);
    serial_putstring(FONT_SET_8X13);
    serial_putstring(CLEAR_SCREEN);

//    command doesn't work?
    serial_putstring(REPORT_CURSOR_POSITION);
   waitCount(1000000);
   waitCount(1000000);
    serial_putstring(CLEAR_SCREEN);
    serial_putstring("Hello");
    T0TC = 0 ;
    T1TC = 0 ;
    waitCount(1000000);
    waitCount(1000000);
    waitCount(1000000);
    serial_putstring(CLEAR_SCREEN);
    serial_putstring(MOVE_UPPER_LEFT);

    waitCount(1000000);
    waitCount(1000000);
    while (1) {
    

	if (timer0_val > MAXTIMER) { 
               T0TC = 0 ; 
	       serial_putstring(CLEAR_SCREEN);
	       serial_putstring("Reset timer");
	       waitCount(1000000);
	       waitCount(1000000);
	       serial_putstring(CLEAR_SCREEN);
	       serial_putstring(MOVE_UPPER_LEFT);
	       waitCount(1000000);
               waitCount(1000000);
          }
	if (timer1_val > MAXTIMER) { 
              T1TC = 0 ;   
               serial_putstring(CLEAR_SCREEN);
	       serial_putstring("Reset timer");
	       waitCount(1000000);
	       waitCount(1000000);
	       serial_putstring(CLEAR_SCREEN);
	       serial_putstring(MOVE_UPPER_LEFT);
	       waitCount(1000000);
               waitCount(1000000);

         }
    // capture timer values
        timer0_val = T0TC;
        timer1_val = T1TC;
//        serial_putstring(CLEAR_SCREEN);
        serial_putstring(MOVE_UPPER_LEFT);


        serial_putstring( itoa(timer0_val,10) );
	
	for(i=0 ; i<15; ++i) {
        serial_putstring(MOVE_CURSOR_RIGHT_ONE);
        }
//        serial_putstring(MOVE_CURSOR_RIGHT_TEN);

//        serial_putstring(MOVE_CURSOR_RIGHT_TWENTY);

        serial_putstring( itoa(timer1_val,10));
	// waitCount(500000);
	//     waitCount(1000000);
	//   waitCount(1000000);
	//    waitCount(1000000);
        //      serial_putstring(PSAS_test);
        //      serial_putstring(CLEAR_SCREEN);
        //      serial_putstring(MOVE_CURSOR_DOWN_FIVE);
        //      serial_putstring(MOVE_CURSOR_DOWN_FIVE);
    }

    return(0);
}


/*
 * initialize
 * -----------------------------------------------
 * initialize the lpc2148 pll 
 * cpu interrupts
 * the uart0 serial port
 * the rtc VIC interrupt
 */
void initialize(void)  {
    // start the pll, connect the clock
    //  CCLK = 48Mhz, Fcco 192Mhz
    //  APBDIV = 01 => 48Mhz PCLK
    pll0_run(0x1,0x3, 0x01);
    
    // enable interrupts in the CPSR
    // enableIRQ();
    
    // enable the leds
    enable_leds();

    // from lpc-timer.h
    ENABLE_TIMER0;
    ENABLE_TIMER1;

    SET_PRESCALE0(1000000);
    SET_PRESCALE1(200);            // run timer 1 at 1/100 of timer 0

    // bob4 board wants 9600 8n1
    // 48Mhz PCLK, divisor is 0x0138 for 9600
    serial0Init(0x138, U0LCR_8N1, U0FCR_EN_ONE_CHAR);
    // 48Mhz PCLK, divisor is 0x1a for 115200
    //    serial0Init(0x1a, U0LCR_8N1, U0FCR_EN_ONE_CHAR);
    // 48Mhz PCLK, divisor is 0x9c for 19200
    // serial0Init(0x9c, U0LCR_8N1, U0FCR_EN_ONE_CHAR);

    // enable the interrupt control register.
    // enableTIMER0_INT(0x4, (unsigned) TIMER0_Handler );


}


/*
 * TIMER0_Handler
 * ------------------------
 * Code TIMER0 interrupt
 */
void TIMER0_Handler (void) {
  
    led1_invert();
    led2_invert();
 
    RESET_T0IR;     // Timer 0 Interrupt flag

    EXIT_INTERRUPT;
}




/*  Stubs for various interrupts (may be replaced later)  */
/*  ----------------------------------------------------  */

void IRQ_Routine (void) {
    while (1) ;
}

void FIQ_Routine (void)  {
    while (1) ;
}


void SWI_Routine (void)  {
    while (1) ;
}


void UNDEF_Routine (void) {
    while (1) ;
}
