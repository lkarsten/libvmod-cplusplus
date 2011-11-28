# add any third party libraries you need
INCLUDES = -I$(VARNISHSRC)/include -I$(VARNISHSRC) 

noinst_PROGRAMS = juicyparts

juicyparts_SOURCES = juicyparts.cpp
juicyparts_CPPFLAGS = -DJUICYPARTS_TEST
#juicyparts_LDADD = -L$(foopath)/lib -lfoo
#juicyparts_LDFLAGS = -Wl,--rpath=$(foopath)/lib

vmoddir = $(VMODDIR)
vmod_LTLIBRARIES = libvmod_cplusplus.la

libvmod_cplusplus_la_LDFLAGS = -module -export-dynamic -avoid-version

#libvmod_cplusplus_la_LIBADD = -L$(foopath)/lib -lfoo

libvmod_cplusplus_la_SOURCES = \
	vcc_if.c \
	vcc_if.h \
	juicyparts.cpp \
	vmod_cplusplus.c

vcc_if.c vcc_if.h: $(VARNISHSRC)/lib/libvmod_std/vmod.py $(top_srcdir)/src/vmod_cplusplus.vcc
	@PYTHON@ $(VARNISHSRC)/lib/libvmod_std/vmod.py $(top_srcdir)/src/vmod_cplusplus.vcc

VMOD_TESTS = tests/*.vtc
.PHONY: $(VMOD_TESTS)

tests/*.vtc:
	$(VARNISHSRC)/bin/varnishtest/varnishtest -Dvarnishd=$(VARNISHSRC)/bin/varnishd/varnishd -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_cplusplus.vcc \
	$(VMOD_TESTS)

CLEANFILES = $(builddir)/vcc_if.c $(builddir)/vcc_if.h
