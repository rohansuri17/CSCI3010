CXX = g++  # the compiler
CXXFLAGS = -std=c++11 -Wall  # flags for the compiler (use c++11 standards, turn on all optional warnings)
GDBINFO = -ggdb # include this to generate info needed to run gdb

all: main test

clean:
	rm test main 

main: main.cpp Counter.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

test: test.cpp
		$(CXX) $(CXXFLAGS) test.cpp -o test
