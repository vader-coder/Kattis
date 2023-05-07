CXX=g++

# UnitTest++ keeps its object files in this library.
UNITTEST_LIB = -lUnitTest++
TARGET = sim
TEST = tests
CXXFLAGS = -g

#try .o version
#https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html

# A special target to build everything
#all: $(TARGET).cpp tests.cpp
#	$(CXX) $(UNITTEST_LIB) -o $(TARGET) $(TARGET).cpp $(TEST)
all: sim.cpp tests.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TEST) $(TEST).cpp $(UNITTEST_LIB)

total: total.cpp
	$(CXX) $(CXXFLAGS) -o total total.cpp

sim: sim.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

tests: tests.cpp
	$(CXX) $(CXXFLAGS) -o $(TEST) $(TEST).cpp $(UNITTEST_LIB)
#g++ -o tests tests.cpp -lUnitTest++
