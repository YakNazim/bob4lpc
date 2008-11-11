
/* 
 * helpers.h
 * -----------------------------------------------
 * Useful preprocessor macros and #defines 
 *
 */


#ifndef _HELPERS_H
#define _HELPERS_H



/*
 * itoa
 * ------------------------------
 * integer to ascii code
 * Copy return to a local variable for long
 * term useage.
 */
char* itoa(int val, int base);


#define MINOF(a,b) ( ( (a) < (b) ) ? (a) : (b) )
#define MAXOF(a,b) ( ( (a) > (b) ) ? (a) : (b) )






#endif /* _HELPERS_H */
