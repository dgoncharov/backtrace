SUBDIRS = src

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = libbacktrace.pc.in

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libbacktrace.pc

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck

