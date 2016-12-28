# SHELL	:= /bin/bash
SBT          ?= sbt
SBT_FLAGS    ?= -Dsbt.log.noformat=true

# .SHELLFLAGS     :=  -e -o pipefail

# If a chiselVersion is defined, use that.
ifneq (,$(chiselVersion))
CHISEL_SMOKE_VERSION    := $(chiselVersion)
CHISEL_CHECK_VERSION    := $(chiselVersion)
CHISEL_DEFAULT_VERSION  := $(chiselVersion)
else
CHISEL_SMOKE_VERSION    ?= 2.3-SNAPSHOT
CHISEL_CHECK_VERSION    ?= 2.3-SNAPSHOT
CHISEL_DEFAULT_VERSION ?= latest.release
endif

top_srcdir  ?= .
srcdir      ?= $(top_srcdir)/src/main/scala
build_dir	?= $(top_srcdir)/build

executables := $(notdir $(basename $(wildcard $(srcdir)/*.scala)))

tst_outs    := $(addsuffix .out, $(executables))

CHISEL_FLAGS = --targetDir $(build_dir)\
	--configInstance saddc.DefaultSADDCConfig

default:  SBT_FLAGS += -DchiselVersion="$(CHISEL_DEFAULT_VERSION)"
default: all

all: cpp verilog

check:  SBT_FLAGS += -DchiselVersion="$(CHISEL_CHECK_VERSION)"
check: test-solutions.xml

clean:
	rm -rf build/*
	rm -rf project/target/ target/

cpp: 
	# set -e -o pipefail; 
	$(SBT) $(SBT_FLAGS) "run $(notdir $(basename $<)) --genHarness --compile --test --backend c $(CHISEL_FLAGS)" | tee $@

verilog: 
	$(SBT) $(SBT_FLAGS) "run $(notdir $(basename $<)) --genHarness --backend v $(CHISEL_FLAGS)"

test-solutions.xml: $(tst_outs)
	$(top_srcdir)/sbt/check $(tst_outs) > $@

smoke:  SBT_FLAGS += -DchiselVersion="$(CHISEL_SMOKE_VERSION)"
smoke:
		$(SBT) $(SBT_FLAGS) compile

.PHONY: all check clean emulator verilog smoke
