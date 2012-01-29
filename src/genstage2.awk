#
# Public Domain.
# NO WARRANTY EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK.
#
# Kaushik Srenevasan (kaushik@sysenter.org)
# 12/25/2009
#
# See http://ksrenevasan.blogspot.com/2005/10/writing-multiboot-pe-kernels-using.html 
#
# This script parses an .rdata section header of a dumpbin log looking
# for the underlined values:
#
# ...
# SECTION HEADER
#   .rdata name
#        E virtual size
#     2000 virtual address (00102000 to 0010200D)
#                           --------    --------
#     1000 size of raw data
#     ----
#     2000 file pointer to raw data (00002000 to 00002FFF)
#        0 file pointer to relocation table
#        0 file pointer to line numbers
#        0 number of relocations
#        0 number of line numbers
# 40000040 flags
#          Initialized Data
#          Read Only
# ...
#

BEGIN { 
        data_section = 0;

        data_section_start = 0;
        data_section_end = 0;
        data_section_size = 0;
}

END {
        print "@echo off"                                            > "build2.cmd";
        print "echo Second build..."                                >> "build2.cmd";
        print "set KERNEL_DATA_SECTION_START=0x" data_section_start >> "build2.cmd";
        print "set KERNEL_DATA_SECTION_END=0x" data_section_end     >> "build2.cmd";
        print "set KERNEL_DATA_SECTION_SIZE=0x" data_section_size   >> "build2.cmd";
        print "set KERNEL"                                          >> "build2.cmd";
        print "nmake /nologo"                                       >> "build2.cmd";
}

/\.rdata name/ { 
        data_section = 1;
}

/virtual address/ { 
        if (data_section) {
                data_section_start = substr($4, 2, 9);
                data_section_end   = substr($6, 1, 8);
        }
}

/size of raw data/ {
        if (data_section) {
                data_section_size = $1;
                data_section = 0;
        }
}
