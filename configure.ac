#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([], [], [dgoncharov@github.com])
AM_INIT_AUTOMAKE([libbacktrace], ["0.1.0"])
AC_CONFIG_SRCDIR([backtrace.hpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

AC_LANG_CPLUSPLUS

AC_LIBTOOL_DLOPEN
AC_PROG_LIBTOOL
AC_SUBST(LIBTOOL_DEPS)
AC_CONFIG_MACRO_DIR([m4])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

AC_CHECK_HEADERS([\
    string vector algorithm],,
    AC_MSG_ERROR([You need to have the C++ standard headers installed]))

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.


AH_TOP([
#ifndef CONFIG_H
#define CONFIG_H])
AH_BOTTOM([#endif /* CONFIG_H */])
CXXFLAGS="$CXXFLAGS -include config.h"

AC_CONFIG_FILES([Makefile src/Makefile libbacktrace.pc])

AC_OUTPUT

