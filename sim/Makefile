CC=g++
CFlags= -ggdb
SOURCES= main.cpp line.cpp handle.cpp print.cpp add.cpp remove.cpp
DEPS= sim.h 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exec 

all: $(EXECUTABLE)
	@echo Make has finished
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp