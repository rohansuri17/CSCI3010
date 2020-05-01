# This is an example make file

CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: main

# runs for "make target1"
# the line below this one must be TABBED in (not spaces!)
# files DependsOn.o and main.cpp will be monitored for changes to know if it needs to be re-made
main: ElectoralMap.o Election.o TextUI.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp ElectoralMap.o Election.o TextUI.o -o main # name of output should be consistent

ElectoralMap.o: ElectoralMap.cpp
	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp
Election.o: Election.cpp
	$(CXX) $(CXXFLAGS) -c Election.cpp
TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp
	

# runs for "make target2"
clean:
	rm ElectoralMap.o Election.o TextUI.o main  #include all targets here
