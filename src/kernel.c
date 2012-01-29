/*
 * Public Domain.
 * NO WARRANTY EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK.
 *
 * Kaushik Srenevasan (kaushik@sysenter.org)
 * 12/25/2009
 *
 * See http://ksrenevasan.blogspot.com/2005/10/writing-multiboot-pe-kernels-using.html
 */

#include "kernel.h"
#include "print.h"

void main(unsigned long magic, unsigned long addr)
{
        print("Hello, World!");
}
