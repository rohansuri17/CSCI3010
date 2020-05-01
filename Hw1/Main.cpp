/**
Rohan Suri
Homework 1
This is a maze game with a player class, board class, and maze class. We have 1 player and 2
moving ememies(also players) in the command line. The enemies move and there are obstacles such as walls and
traps(fire). We use the command line to move through the maze to try to ger to the end
*/
#include <iostream>
#include <vector>
#include "Player.h"
#include "Maze.h"


int main()
{
  Player *p = new Player("Rohan",true);
  Maze maze1 = Maze();
  maze1.NewGame(p,2);
  Player *next_player = p;
  std::cout<<maze1<<std::endl; 
  while(!maze1.IsGameOver())
  {
    maze1.TakeTurn(next_player);
    next_player = maze1.GetNextPlayer();
    std::cout<<maze1<<std::endl;
   }
  std::cout<<maze1.GenerateReport();
}