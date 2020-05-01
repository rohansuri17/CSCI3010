/**
Rohan Suri
Homework 1
This is the Maze.cpp file of the Maze game with 1 player and 2 enemies. This cpp file, along with Maze.h,
creates the board and the maze class to be used along with the player class defined in a different file
Fire trap now implemented to make the game better. see SquareTypeStringify below.
*/

#include <iostream>
#include <vector>
#include "Player.h"
#include "Maze.h"
#include<cstdlib>
#include<ctime>
#include <string> 
/**
Returns an emoji string based on the SquareType(in argument)

@param SquareType object An object from the SquareType enum class which defines
different objects in the maze
@return emoji string based on SqaureType from enum class
*/
std::string SquareTypeStringify(SquareType sq)
{
  if(sq==SquareType::Wall)
  {

    return "🚧";

  }
  else if(sq==SquareType::Exit)
  {

    return "💯";

  }
  else if(sq==SquareType::Human)
  {

    return "🤵";

  }
  else if(sq==SquareType::Empty)
  {

    return "⬜";

  }
  else if(sq==SquareType::Enemy)
  {

    return "👺";

  }
  else if(sq==SquareType::Treasure)
  {

    return "🏆";

  }
  else if(sq==SquareType::Fire)//ADDED FIRE AS AN EXTRA TRAP TO MAKE THE GAME IMPROVED
  {
    return "🔥";
  }
  return "Didn't work";
}
/**
Default Constructor that puts the different SquareType enum objects in the maze based on their
probability. They are as follows: Treasure 10% chance, Wall 20% chance, Fire 5% chance.
Human is initialized at (0,0) on board and Exit at (3,3) assuming we have 4 rows.
*/
Board::Board()
{
  std::srand(std::time(NULL));//random seed generator
  int rand = std::rand()%100+1;//numbers between 1 and 100

  for (int i = 0; i < get_rows(); i++)
  {

    for (int j = 0; j < get_cols(); j++)
    {
      arr_[i][j] = SquareType::Empty;
      rand = std::rand()%100+1;

      if (rand <= 10 && arr_[i][j] == SquareType::Empty)//10% chance
      {
        arr_[i][j] = SquareType::Treasure;
      }
      
      if (rand > 10 && rand <= 31)//20% chance of wall
      {
        arr_[i][j] = SquareType::Wall;
      }

      if(rand > 31 && rand <= 36) //5% chance
      {
        arr_[i][j] = SquareType::Fire;
      }

    }
  }
  arr_[0][0] = SquareType::Human;//human at (0,0)
  arr_[3][3] = SquareType::Exit;//exit at (3,3)

  
}
/**
Return SquareType of the position provided(in args)
@param Position object defined with the Position struct in Player.h
@return SquareType of the given position ex. Enemy, Wall etc.
*/
SquareType Board::get_square_value(Position pos) const
{

  return arr_[pos.row][pos.col];

}
/**
Return None
@param Position object and a SquareType object from the SquareType enum class
@return None
*/
void Board::SetSquareValue(Position pos, SquareType value)
{
  arr_[pos.row][pos.col] = value;
}
/**
Return a vector that lists out every possible move such that you don't hit a wall or go out of bounds
@param a Player object
@return a vector listing out all applicable moves based on rules mentioned above
*/
std::vector<Position> Board::GetMoves(Player *p)
{
  Position move = p->get_position(); 
  std::vector<Position> list_moves;
  move.row++; 
  if(get_square_value(move) != SquareType::Wall && get_square_value(move) != SquareType::Enemy&&p->get_position().row < 3)//if there is not a wall or enemy below player
  {
    if(p->get_position().row < 3)
    {
      list_moves.push_back(move);//it is a possible move
    }
  }

  move = p->get_position();
  move.row--;
  if(get_square_value(move) != SquareType::Wall && get_square_value(move) != SquareType::Enemy)//if there is not a wall or enemy above player
  {
    if(p->get_position().row > 0)
    {
      list_moves.push_back(move);//it is a possible move

    }
  }

  move = p->get_position();
  move.col++;
  if(get_square_value(move) != SquareType::Wall && get_square_value(move) != SquareType::Enemy)//if there is not a wall or enemy right of player
  {
    if(p->get_position().col < 3)
    {
       list_moves.push_back(move);//it is a possible move

    }

  }

  move = p->get_position();
  move.col--; //to check the column to the left of our player
  if(get_square_value(move) != SquareType::Wall && get_square_value(move) != SquareType::Enemy)//if there is not a wall or enemy left of player
  {
    if(p->get_position().col > 0)
    {
      list_moves.push_back(move);//it is a possible move
    }

    

  }

  return list_moves;

}
/**
Return A bool based on players successful movement to the desired square on the board
@param A player object and the players current position
@return True for successful movement to desired position and 
false if unable to move in that direction 
*/
bool Board::MovePlayer(Player *p, Position pos)
{
  Position prev_player_pos = p->get_position();
  SquareType next = arr_[pos.row][pos.col];
  if(p->is_human() && next == SquareType::Fire)//if human and next square is fire
  {
    arr_[pos.row][pos.col] = SquareType::Fire;
    std::cout << "Uh oh, you got burnt by the fire!" << std::endl;
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;
  }

  if (p->is_human() && next == SquareType::Treasure) //if human and next square is treasure
  {
    p->ChangePoints(100);
    arr_[pos.row][pos.col] = SquareType::Human;
    p->SetPosition(pos);
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;

  }
  if (!p->is_human() && next == SquareType::Treasure) //if enemy and next square is treasure
  {
    p->ChangePoints(100);
    arr_[pos.row][pos.col] = SquareType::Enemy;
    p->SetPosition(pos);
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;

  }

  if (p->is_human() && next == SquareType::Enemy) //if human and next square is enemy
  {
    arr_[pos.row][pos.col] = SquareType::Enemy;
    std::cout << "Uh oh, you got killed by the enemy. GAME OVER X.X" << std::endl;
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;
  }
  else if (p->is_human() && next == SquareType::Exit) //if human and next square is exit
  {
    p->ChangePoints(1);
    std::cout << "You Win!" << std::endl;
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;
    }
  else if(p->is_human() && next == SquareType::Empty)//if human and next square is empty
  {
    arr_[pos.row][pos.col] = SquareType::Human;//set square type to human
    p->SetPosition(pos);//move human
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;
  }
  else if(!p->is_human() && next == SquareType::Human)//if enemy and next square is human
  {
    arr_[pos.row][pos.col] = SquareType::Enemy;
    std::cout << "Uh oh, you got killed by the enemy. GAME OVER X.X" << std::endl;
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;
  }
  else if(!p->is_human())//last condition if not human
  {
    arr_[prev_player_pos.row][prev_player_pos.col] = SquareType::Empty;
    arr_[pos.row][pos.col] = SquareType::Enemy;
    p->SetPosition(pos);
  }
  
  if (p->get_position() == pos) 
  {
    return true;
  }
  return false;
}
/**
Return true if there is a human on the board, false if not
@param None
@return true if human on the board, false if not
*/
bool Board::Exited() {
  for (int i = 0; i < 4; i++) 
  {
    for (int j = 0; j < 4; j++) 
    {
      if (arr_[i][j] == SquareType::Human) //checks if any of the squares are human
      {
        return true;
      }
    }
  }

  return false;
}
/**
Return Location of the exit of the maze/board
@param None
@Return Location of the exit of the maze/board(SquareType object)
*/
SquareType Board::GetExitOccupant()
{
  return arr_[3][3];
}
/**
Return Std << for Board overloaded for emojis
@param os std << and constantBoard object
@return Std << for Board overloaded for emojis
*/
std::ostream& operator<<(std::ostream& os, const Board &b)
{

  for(int i = 0; i < 4; i++){

    for(int j = 0; j < 4; j++){

      os<<SquareTypeStringify(b.arr_[i][j]);
    }

    os<<std::endl;

  }

return os;
}
/**
Default constructor of the Maze class that creates a new board, initialized the turn_count_
and sets our bool moved_ to true by default
*/
Maze::Maze()
{
  board_ = new Board();
  turn_count_ = 0;
  moved_ = true;
}
/**
Return None
@param Player object and a constant number of enemies as an int
@return None
*/
void Maze::NewGame(Player *human, const int enemies)
{

  Position human_init_pos = {0,0};
  human->SetPosition(human_init_pos); //sets initial position of human to 0,0
  players_.push_back(human);
  board_ = new Board();
  int i = 0;

  while(i < enemies)
  {
    Position enemy_positon = {rand() % board_->get_rows(), rand() % board_->get_cols()};// random enemy positions
    if(board_->get_square_value(enemy_positon) == SquareType::Empty)
    {

      Player *enemy = new Player("enemy"+std::to_string(i), false); //creates new enemies in loop based on int enemies
      enemy->SetPosition(enemy_positon);//sets position to random position
      board_->SetSquareValue(enemy_positon, SquareType::Enemy); 
      players_.push_back(enemy);
      i++;
      }
  }
}
/**
Return None
@param Player object
@return None
*/
void Maze::TakeTurn(Player *p)
{

  std::vector<Position> list_of_moves = board_->GetMoves(p);
  std::cout<<p->get_name()<<" can go the following directions: ";
  for(unsigned int i = 0; i < list_of_moves.size(); i++)
  {
    std::cout<<p->ToRelativePosition(list_of_moves.at(i))<<" ";
  }

  std::  cout<<std::endl<<"Enter the direction you would like to go: ";
  std::string dir;              
  std::cin>>dir;//takes in user input of direction player to go
  std::string uppercase ="";
  bool check = false;//to check if after the for loop ALL moves were successful
  for (unsigned int i = 0; i < dir.length(); i++)
      uppercase += std::toupper(dir[i]);//converts to uppercase so we can compare later
   std::cout<<uppercase<<std::endl;
  
  for(unsigned int i = 0; i < list_of_moves.size(); i++)
  {
    std::cout<<p->ToRelativePosition(list_of_moves.at(i))<<std::endl;
      if (uppercase == p->ToRelativePosition(list_of_moves.at(i))){//compare our input the list of possible moves
          moved_=board_->MovePlayer(p, list_of_moves.at(i));
          //std::cout<<movesuccess_<<"THIS IS IT BOYS"<<std::endl;
          check = true;
          turn_count_++;
      }
  }
  if(check == false){//if any of the checks failed 
    moved_=false;//we haven't moved
    std::cout<<"Wasn't able to move bro";
  }
  
}
/**
Return Player object of the next player in the list
@param None
@return Player object of the next player in the list
*/   
Player * Maze::GetNextPlayer()
  {
   return players_.at(turn_count_ % players_.size());//gets remainder for index with respect to turn count... works with all size players
  }
/**
Return bool based on if the game is over or not
@param None
@return bool based on if the game is over or not
*/
bool Maze::IsGameOver(){

  if (board_->GetExitOccupant() == SquareType::Human)//if human is on exit
  {
    return true;

  } 
  if (!board_->Exited())//if human isn't on the board anymore
  {
    return true;

  } 
  return false;
}
/**
Return a string report of each players name and point value
@param None
@return String report for each players name and point value
*/
std::string Maze::GenerateReport()
{
  std::string report;
  for(unsigned int i=0; i<players_.size(); i++)
  {

    report += players_[i]->get_name() + " has " + std::to_string(players_[i]->get_points()) + " points." + "\n";

  }
  return report;
}
/**
Return std << overloaded for maze
@param std output and const maze object
@return std << overloaded for maze
*/
std::ostream& operator<<(std::ostream& os, const Maze &m){

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      Position temp = {i,j};
      std::string a = SquareTypeStringify(m.board_->get_square_value(temp));
      os << a <<" ";
    }
    os << std::endl;
  }
  return os;
}