ifndef CUDA_HOME
CUDA_HOME:=/usr/local/cuda
endif

ifndef EXERCISE
EXERCISE=lu_cuda.cu
endif

BUILD_DIR ?= ./build

NVCC=$(CUDA_HOME)/bin/nvcc
CXX=g++

OPT:=-O3
NVOPT:=-Xcompiler -fopenmp -lineinfo -arch=sm_53

CXXFLAGS:=$(OPT) -I. -I ../utilities $(EXT_CXXFLAGS)
LDFLAGS:=-lm -lcudart $(EXT_LDFLAGS)

NVCFLAGS:=$(CXXFLAGS) $(NVOPT)
NVLDFLAGS:=$(LDFLAGS) -lgomp

SRCS:= utils.c
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o) $(EXERCISE:%=$(BUILD_DIR)/%.o)
EXE=$(EXERCISE:.cu=.exe)

$(EXE):	$(OBJS)
	$(MKDIR_P) $(dir $@)
	$(NVCC) $(NVCFLAGS) $(OBJS) -o $@ $(NVLDFLAGS)

$(BUILD_DIR)/%.cu.o: %.cu
	$(MKDIR_P) $(dir $@)
	$(NVCC) $(NVCFLAGS) -c $< -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(EXE)

.PHONY: run profile clean
run: $(EXE)
	./$(EXE)

profile: $(EXE)
	sudo LD_LIBRARY_PATH=$(CUDA_HOME)/lib:/usr/ext/lib:${LD_LIBRARY_PATH} LIBRARY_PATH=/usr/ext/lib:${LIBRARY_PATH} $(CUDA_HOME)/bin/nvprof --unified-memory-profiling off ./$(EXE)

metrics: $(EXE)
	sudo LD_LIBRARY_PATH=$(CUDA_HOME)/lib:/usr/ext/lib:${LD_LIBRARY_PATH} LIBRARY_PATH=/usr/ext/lib:${LIBRARY_PATH} $(CUDA_HOME)/bin/nvprof --print-gpu-trace --metrics "eligible_warps_per_cycle,achieved_occupancy,sm_efficiency,ipc" ./$(EXE)

clean:
	-rm -fr $(BUILD_DIR) *.exe *.out *~

benchmark: $(EXE)
	../utilities/time_benchmark.sh ./$(EXE)

MKDIR_P ?= mkdir -p
