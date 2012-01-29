@echo off
REM
REM Public Domain.
REM NO WARRANTY EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK.
REM
REM Kaushik Srenevasan (kaushik@sysenter.org)
REM 12/25/2009
REM 
REM See http://ksrenevasan.blogspot.com/2005/10/writing-multiboot-pe-kernels-using.html
REM

set KERNEL_DATA_SECTION_START=0
set KERNEL_DATA_SECTION_END=0
set KERNEL_DATA_SECTION_SIZE=0

echo First build to calculate section sizes...
nmake /nologo

echo Reading sizes from dumpbin output...
dumpbin /ALL bin\kernel.exe | gawk -f genstage2.awk

REM
REM AWK generates a new file called build2.cmd which does the second build
REM

call build2.cmd
rm build2.cmd

set KERNEL_DATA_SECTION_START=
set KERNEL_DATA_SECTION_END=
set KERNEL_DATA_SECTION_SIZE=
