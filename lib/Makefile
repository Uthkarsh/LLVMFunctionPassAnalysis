# Makefile for hello pass

# Path to top level of LLVM hierarchy
LEVEL = ../..

# Name of the library to build
LIBRARYNAME = cs565opt

# Make the shared library become a loadable module so the tools can
# dlopen/dlsym on the resulting library.
LOADABLE_MODULE = 1

# Might need to change this to .so in LINUX
LIB_EXT = .dylib

TEST_PRINT = $(LEVEL)/../bin/opt -load $(LEVEL)/../lib/$(LIBRARYNAME)$(LIB_EXT) -FunctionPassAnalysis <
FUNC_CALLS = $(LEVEL)/../bin/opt -load $(LEVEL)/../lib/$(LIBRARYNAME)$(LIB_EXT) -funcCall <
# Include the makefile implementation stuff
include $(LEVEL)/Makefile.common

typeCheck:
	$(TEST_PRINT) ../tests/mytest2.bc > /dev/null

funcCall:
	$(FUNC_CALLS) ../tests/mytest2.bc > /dev/null

