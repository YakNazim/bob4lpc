
/*
 * helpers.c
 * ---------------------------
 * sometimes useful code.
 */


#include <string.h>

/*
 * itoa
 * ------------------------------
 * integer to ascii code
 * Copy return to a local variable for long
 * term useage.
 */
/* char* itoa(int val, int base){ */

/*     static char buf[32] = {0}; */

/*     int i = 30; */

/*     if(val == 0) { return "0"; } */
/*     else { */
/* 	for(; val && i ; --i, val /= base) */

/* 	    buf[i] = "0123456789abcdef"[val % base]; */

/* 	return &buf[i+1]; */
/*     } */
/* } */


/********The function itoa appeared in the first edition of Kernighan and
 * Ritchie's The C Programming Language, on page 60. The second edition of The
 * C Programming Language ("K&R2") contains the following implementation of
 * itoa, on page 64. The book notes several issues with this implementation,
 * including the fact that it does not correctly handle the most negative
 * number −2wordsize-1.[1] */

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
} 



