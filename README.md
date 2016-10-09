# test
test

1. autoscan
mv configure.scan configure.ac
vim configure.ac

#                                               -*- Autoconf -*-
 # Process this file with autoconf to produce a configure script.
  
 AC_PREREQ([2.69])
 AC_INIT([test], [0.1], [frank75@interia.pl])
 AM_INIT_AUTOMAKE
 AC_CONFIG_SRCDIR([main.c])
 #AC_CONFIG_HEADERS([config.h])
   
 # Checks for programs.
 AC_PROG_CC
  
 # Checks for libraries.
 
 # Checks for header files.
 AC_CHECK_HEADERS([stdlib.h])
  
 # Checks for typedefs, structures, and compiler characteristics.
 
 # Checks for library functions.
 AC_CONFIG_FILES([Makefile])
 AC_OUTPUT

3. vim Makefile.am

AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = main
main_SOURCES = main.c test.c

4. 
aclocal
autoconf
automake --add-missing # Generate Makefile.in from Makefile.am
./configure # Generate Makefile from Makefile.in

===
Summary:

aclocal # Set up an m4 environment
autoconf # Generate configure from configure.ac
automake --add-missing # Generate Makefile.in from Makefile.am
./configure # Generate Makefile from Makefile.in
make distcheck # Use Makefile to build and test a tarball to distribute


