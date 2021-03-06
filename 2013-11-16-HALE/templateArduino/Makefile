# Files
EXE = app
LIBRARIES = ../libraries

SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, build/%.o, $(SRC))
DEPS = $(patsubst %.cc, build/%.d, $(SRC))

# Settings
DEVICE ?= -1
DEBUG ?= FALSE

# Programs
CXX = g++-4.7
LD = g++-4.7

# Include directories
INC = -I $(LIBRARIES)/thelonious -I $(LIBRARIES)/jellyroll -I $(LIBRARIES)/elvin -I $(LIBRARIES)/miles -I $(LIBRARIES)/FirmataC/includes -I $(LIBRARIES)/arduino

# Libraries
LIB = -lrtaudio -lasound -lpthread -lfirmatac

# Compile flags
CXXFLAGS = -std=c++11 -Werror -Wall -Wno-parentheses -pedantic
ifeq (DEBUG, TRUE)
CXXFLAGS += -g -O0
endif
CXXFLAGS += -D__LINUX_ALSA__ -DAUDIO_DEVICE=$(DEVICE)

# Link flags
LDFLAGS = -L$(LIBRARIES)/FirmataC

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

