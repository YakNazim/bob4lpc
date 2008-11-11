
/*
 * helpers.c
 * ---------------------------
 * sometimes useful code.
 */


/*
 * itoa
 * ------------------------------
 * integer to ascii code
 * Copy return to a local variable for long
 * term useage.
 */
char* itoa(int val, int base){

    static char buf[32] = {0};

    int i = 30;

    if(val == 0) { return "0"; }
    else {
	for(; val && i ; --i, val /= base)

	    buf[i] = "0123456789abcdef"[val % base];

	return &buf[i+1];
    }
}




