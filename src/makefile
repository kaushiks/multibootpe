#
# Public Domain.
# NO WARRANTY EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK.
#
# Kaushik Srenevasan (kaushik@sysenter.org)
# 12/25/2009
# 
# See http://ksrenevasan.blogspot.com/2005/10/writing-multiboot-pe-kernels-using.html
#

TARGET                    = kernel
CC                        = cl.exe /nologo
CFLAGS                    = /c /TC /Gd /Ox /O2 /Oy-
LINK                      = link.exe /NOLOGO
LINK_FLAGS                = /SAFESEH:NO /FILEALIGN:$(KERNEL_ALIGN) /NODEFAULTLIB:LIBC /SUBSYSTEM:CONSOLE
BIN                       = bin
DEL                       = del /Q /F

# these are environment variables that are set by stage 2
# KERNEL_DATA_SECTION_START
# KERNEL_DATA_SECTION_END
# KERNEL_DATA_SECTION_SIZE
KERNEL_BASE               = 0x100000
KERNEL_PAGE_SIZE          = 0x1000
KERNEL_ALIGN              = 0x1000

all: kernel

kernel: multiboot.obj kernel.obj print.obj
	@$(LINK) $(LINK_FLAGS)                                          \
	/BASE:$(KERNEL_BASE)                                            \
	/MAP:$(BIN)\$(TARGET).map                                       \
	/ENTRY:__multiboot_entry__                                      \
	/OUT:$(BIN)\$(TARGET).exe                                       \
	$(BIN)\multiboot.obj                                            \
	$(BIN)\kernel.obj                                               \
	$(BIN)\print.obj

multiboot.obj: multiboot.c multiboot.h
	@$(CC) $(CFLAGS)                                                \
	/DKERNEL_PAGE_SIZE=$(KERNEL_PAGE_SIZE)                          \
	/DKERNEL_DATA_SECTION_START=$(KERNEL_DATA_SECTION_START)        \
	/DKERNEL_DATA_SECTION_END=$(KERNEL_DATA_SECTION_END)            \
	/DKERNEL_DATA_SECTION_SIZE=$(KERNEL_DATA_SECTION_SIZE)          \
	/Fo$(BIN)\multiboot.obj                                         \
	multiboot.c

kernel.obj: kernel.c kernel.h print.h
	@$(CC) $(CFLAGS) /Fo$(BIN)\kernel.obj kernel.c

print.obj: print.c print.h
	@$(CC) $(CFLAGS) /Fo$(BIN)\print.obj print.c

clean:
	@$(DEL) *.i 2> nul
	@$(DEL) $(BIN)\* 2> nul
