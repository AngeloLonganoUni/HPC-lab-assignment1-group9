# -include ../../../utilities/options.mk
# -include ../../../utilities/c2.mk
UTIL_DIR = ../utilities

INCPATHS = -I$(UTIL_DIR)

BENCHMARK = $(shell basename `pwd`)
EXE = $(BENCHMARK)_acc
SRC = $(BENCHMARK).c
HEADERS = $(BENCHMARK).h

SRC += $(UTIL_DIR)/polybench.c

DEPS        := Makefile.dep
DEP_FLAG    := -MM

CC=gcc
LD=ld
OBJDUMP=objdump

OPT=-O3 -fopenmp
CFLAGS=$(OPT) -I. $(EXT_CFLAGS)
LDFLAGS=-lm $(EXT_LDFLAGS)

.PHONY: all exe clean veryclean

all : exe

exe : $(EXE)

$(EXE) : $(SRC)
	$(CC) $(CFLAGS) $(INCPATHS) $^ -o $@ $(LDFLAGS)

clean :
	rm -f $(EXE) *~

veryclean : clean
	-rm -vf $(DEPS)

run: $(EXE)
	./$(EXE)

benchmark: $(EXE)
	$(UTIL_DIR)/time_benchmark.sh ./$(EXE)

$(DEPS): $(SRC) $(HEADERS)
	$(CC) $(INCPATHS) $(DEP_FLAG) $(SRC) > $(DEPS)

-include $(DEPS)