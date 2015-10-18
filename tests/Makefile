# Makefile for tests; generates unoptimized .ll IR for all tests

# Test files
FILES = test1.bc test2.bc test3.bc

##
LLVM_ROOT = ../../..
CLANG = $(LLVM_ROOT)/bin/clang
CLANG_FLAGS = -g -emit-llvm -O0 -Weverything
DIS = $(LLVM_ROOT)/bin/llvm-dis
LLC = $(LLVM_ROOT)/bin/llc

all: $(FILES)

clean:
	rm -f *.bc *.ll *.s $(FILES:%.bc=%)

%.bc: %.c
	$(CLANG) $(CLANG_FLAGS) -c $(@:%.bc=%.c) -o $@
	$(DIS) -f $@
	$(LLC) $@
	gcc $(@:%.bc=%.s) -o $(@:%.bc=%)
	
mytest2.bc: mytest2a.c mytest2b.c
			$(CLANG) $(CLANG_FLAGS) -c mytest2a.c -o mytest2a.bc
			$(CLANG) $(CLANG_FLAGS) -c mytest2b.c -o mytest2b.bc
			../../Debug+Asserts/bin/llvm-link mytest2a.bc mytest2b.bc -o mytest2.bc
			$(DIS) -f $@