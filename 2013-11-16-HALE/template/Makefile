# Files
EXE = app
SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, build/%.o, $(SRC))
DEPS = $(patsubst %.cc, build/%.d, $(SRC))
LIBRARIES = ../../libraries

# Settings
DEVICE ?= -1
DEBUG ?= FALSE

# Programs
CXX = g++
LD = g++

# Include directories
INC = -I $(LIBRARIES)/thelonious -I $(LIBRARIES)/jellyroll -I $(LIBRARIES)/elvin -I $(LIBRARIES)/miles

# Libraries
LIB = -lrtaudio -lasound -lpthread

# Compile flags
CXXFLAGS = -std=c++11 -Werror -Wall -Wno-parentheses -pedantic
ifeq (DEBUG, TRUE)
CXXFLAGS += -g -O0
endif
CXXFLAGS += -D__LINUX_ALSA__ -DAUDIO_DEVICE=$(DEVICE)

# Link flags
LDFLAGS =

all: $(EXE)

$(EXE) : $(OBJ) $(DEPS)
	$(LD) $(LDFLAGS) $(OBJ) -o $(EXE) $(LIB)
	

$(OBJ) : | build

$(DEPS) : | build

build:
	@mkdir -p $@

build/%.o: %.cc
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@

build/%.d: %.cc
	$(CXX) $(INC) $(CXXFLAGS) -MM $< -MF $@

clean:
	rm -rf $(EXE) $(OBJ) $(DEPS) build

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPS)
endif

