## Process this file with automake to produce Makefile.in
#
# src/components/verilog/Makefile.am
#
# Automake input file for the verilog device library.
#
# Copyright (C) 2006-2011 Stefan Jahn <stefan@lkcc.org>
# More models added 2013 Mike Beinson mbrin72043@yahoo.co.uk
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this package; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
# Boston, MA 02110-1301, USA.
#

# the verilog devices library rules

noinst_LTLIBRARIES = libverilog.la

XML_BUILD = \
  $(srcdir)/analogfunction.xml \
  $(srcdir)/qucsVersion.xml \
  $(srcdir)/qucsMODULEcore.xml \
  $(srcdir)/qucsMODULEdefs.xml

.va.cpp: $(XML_BUILD)
	for i in $(XML_BUILD); do \
	  echo "$$i"; \
	  es="$$es -e $$i"; \
	done; \
	echo "$(ADMSXML) $< $$es -o $*"; \
	$(ADMSXML) $< $$es -o $*

.va.cpp:

VA_FILES = \
	fbh_hbt-2_2a.va \
	hicumL2V2p11.va \
	mod_amp.va \
	hicumL2V2p22.va \
	log_amp.va \
	hicumL0V1p12.va \
	potentiometer.va \
	MESFET.va \
	EKV26MOS.va \
	bsim3v34nMOS.va \
	bsim3v34pMOS.va \
	bsim4v30nMOS.va \
	bsim4v30pMOS.va \
	hicumL0V1p2.va \
	hicumL0V1p2g.va \
	hicumL0V1p3.va \
	hicumL2V2p23.va \
	hicumL2V2p24.va \
	hicumL2V2p31n.va \
	photodiode.va \
	phototransistor.va \
	nigbt.va \
	\
	dff_SR.va \
	tff_SR.va \
	jkff_SR.va \
	gatedDlatch.va \
	logic_0.va \
	logic_1.va \
	mux2to1.va \
	mux4to1.va \
	mux8to1.va \
	DLS_nto1.va \
	DLS_1ton.va \
	andor4x2.va \
	andor4x3.va \
	andor4x4.va \
	dmux2to4.va \
	dmux3to8.va \
	dmux4to16.va \
	ha1b.va \
	fa1b.va \
	fa2b.va \
	pad2bit.va \
	pad3bit.va \
	pad4bit.va \
	binarytogrey4bit.va \
	greytobinary4bit.va \
	comp_1bit.va \
	comp_2bit.va \
	comp_4bit.va \
	hpribin4bit.va \
	vcresistor.va

libverilog_la_SOURCES = $(VA_FILES)
VERILOGdir=$(pkgdatadir)/verilog

VERILOG_DATA = $(VA_FILES) constants.vams disciplines.vams

VERILOGDIGITAL_FILES =

XML_FILES = analogfunction.xml \
  qucsVersion.xml    \
  qucsMODULEcore.xml \
  qucsMODULEdefs.xml \
  qucsMODULEgui.xml \
  qucsMODULEguiJSONsymbol.xml

MAKE_FILES = cpp2lib.makefile\
  va2cpp.makefile

VA_INCLUDES = constants.vams disciplines.vams

EXTRA_DIST = $(VERILOG_DATA) $(XML_FILES) $(MAKE_FILES)

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/math \
  -I$(top_srcdir)/src/components -I$(top_srcdir)/src/components/devices \
  -I$(builddir)

if MAINTAINER_MODE
## configure determines if we want to build and use the
## bundled version of ADMS, or the host's ADMS. Here we
## set the path to the admsXml binary depeding on the choice
## the user made at configure time

## FIXME: let configure.ac decide
if USE_INTERNAL_ADMS
ADMSXML = $(abs_top_builddir)/deps/adms/admsXml/admsXml
else
ADMSXML = @ADMSXML@
endif

GENERATED_FILES = *.core.* *.analogfunction.* *.gui.* *.defs.* .*.adms .*.xml
else
GENERATED_FILES =
endif

pkginclude_HEADERS = $(XML_FILES) $(MAKE_FILES) $(VA_INCLUDES)

CLEANFILES = *~ *.orig *.rej *.analogfunction.cpp *.core.cpp .*.adms \
             *.core.h *.analogfunction.h *.cpp *.defs.h

MAINTAINERCLEANFILES = Makefile.in $(GENERATED_FILES)
