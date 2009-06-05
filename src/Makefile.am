SUBDIRS = 

# the library name to build
#lib_LIBRARIES = libbacktrace.a
lib_LTLIBRARIES = libbacktrace.la

# the list of header files that belong to the library
libbacktrace_la_HEADERS = $(top_srcdir)/include/backtrace/backtrace.hpp

# where to install the headers on the system
libbacktrace_ladir = $(includedir)/backtrace

# the sources to add to the library and to add to the distribution
libbacktrace_la_SOURCES = $(libbacktrace_la_HEADERS) $(top_srcdir)/src/backtrace.cpp
libbacktrace_la_LDFLAGS = -avoid-version -no-undefined
# additional include pathes necessary
INCLUDES = -I$(top_srcdir)/include
libbacktrace_la_LIBADD = -lboost_regex

