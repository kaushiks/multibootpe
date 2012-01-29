/*
 * Public Domain.
 * NO WARRANTY EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK.
 *
 * Kaushik Srenevasan (kaushik@sysenter.org)
 * 12/25/2009
 *
 * See http://ksrenevasan.blogspot.com/2005/10/writing-multiboot-pe-kernels-using.html
 */

#include "print.h"

void print(char *string)
{
        char *ch;
        unsigned short *vidmem = (unsigned short *) 0xB8000;
        int i;
        
        for(ch = string, i = 0; *ch; ch++, i++)
                vidmem[i] = (unsigned char) *ch | 0x0700;
}
