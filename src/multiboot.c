/*
 * Public Domain.
 * NO WARRANTY EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK.
 *
 * Kaushik Srenevasan (kaushik@sysenter.org)
 * 12/25/2009
 *
 * See http://ksrenevasan.blogspot.com/2005/10/writing-multiboot-pe-kernels-using.html
 */

#include "multiboot.h"
#include "kernel.h"

__declspec(naked) void __multiboot_entry__(void)
{
          __asm {
          
          multiboot_header:
                    dd(0x1BADB002)                ; magic
                    dd(1 << 16)                   ; flags
                    dd(-(0x1BADB002 + (1 << 16))) ; checksum
                    dd(0x00101000)                ; header_addr
                    dd(0x00101000)                ; load_addr
                    dd(KERNEL_LENGTH)             ; load_end_addr
                    dd(KERNEL_LENGTH)             ; bss_end_addr
                    dd(0x00101030)                ; entry_addr
                    dd(0x00000000)                ; mode_type
                    dd(0x00000000)                ; width
                    dd(0x00000000)                ; height
                    dd(0x00000000)                ; depth

          kernel_entry:
                    mov    esp,     KERNEL_STACK

                    xor    ecx,     ecx
                    push   ecx
                    popf

                    push   ebx
                    push   eax
                    call   main

                    jmp    $
          }
}
