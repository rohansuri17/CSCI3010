CXX = g++
CXXFLAGS = -std=c++17 -Wall 

all: main

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp 

Maze.o: Maze.cpp
	$(CXX) $(CXXFLAGS) -c Maze.cpp

clean:
	rm Player.o Maze.o

main: Player.o Maze.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Player.o Maze.o -o main


