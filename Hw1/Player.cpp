/**
Rohan Suri
Homework 1
This is the Player.cpp file used to define the attributes in different functions and private variables
about the different players in the maze game
*/
#include <string>
#include <iostream>
#include "Player.h"
#include "Maze.h"
/**
Overloaded player constructor that initializes the name_, is_human, and points_ variables
*/
Player::Player(const std::string name, const bool is_human){

    name_ = name;
    is_human_= is_human;
    points_ = 0;
}
/**
Return None
@param constant integer point value
@return None
*/
void Player::ChangePoints(const int x){
  
    points_ += x;
}
/**
Return None
@param Position object to be used in a setter function
@return None
*/
void Player::SetPosition(Position pos){

    pos_=pos;

}
/**
Return a string returning a direction relative to the players position
@param Position object which is going to be compared relative to player position
@return a string returning a direction relative to the players position
*/
std::string Player::ToRelativePosition(Position other){

  if(other.row < pos_.row){//compare player row to argument row
    return "UP";
  }
  else if(other.row > pos_.row){
    return "DOWN";
  }
  else if(other.col < pos_.col){
    return "LEFT";
  }
  else if(other.col > pos_.col){
    return "RIGHT";
  }
  return "You're trapped!";
}
/**
Return a specific players name and point value as a string
@param None
@return string of player objects name and point value
*/

std::string Player::Stringify(){

  std::string points_string = std::to_string(points_);//converts points to a strin so we can return as a string

  return name_ + ": " + points_string;

  }