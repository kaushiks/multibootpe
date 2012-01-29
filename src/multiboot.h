/*
 * Public Domain.
 * NO WARRANTY EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK.
 *
 * Kaushik Srenevasan (kaushik@sysenter.org)
 * 12/25/2009
 *
 * See http://ksrenevasan.blogspot.com/2005/10/writing-multiboot-pe-kernels-using.htmlw
 */

#ifndef __multiboot_h__
#define __multiboot_h__

#define dd(x)                            \
        __asm _emit (x)       & 0xff     \
        __asm _emit (x) >> 8  & 0xff     \
        __asm _emit (x) >> 16 & 0xff     \
        __asm _emit (x) >> 24 & 0xff

#define KERNEL_STACK_SIZE (KERNEL_PAGE_SIZE * 5)
#define KERNEL_STACK      ((KERNEL_DATA_SECTION_START + KERNEL_DATA_SECTION_SIZE) + KERNEL_STACK_SIZE - 1)
#define KERNEL_LENGTH     KERNEL_DATA_SECTION_END

#endif /* __multiboot_h__ */
