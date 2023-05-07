CC=g++
CFlags= -ggdb
SOURCES= tests.cpp line.cpp handleChars.cpp print.cpp moveCursor.cpp
DEPS= sim.h 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exec 

all: $(EXECUTABLE)
	@echo Make has finished
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp