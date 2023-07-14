#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "Player.h"
#include "Room.h"
#include <vector>
#include <string>
#include <iostream>

/**
* @class Gamestate Gamestate.h "Gamestate.h"
* @brief A factory method used to dictate the state of game and movement
*/
class GameState {
 public:
 /** 
 * @brief Movement functions
 * @param[in] value representing which option for movement is used
 * @throw errMessage If input is not one of the accepted values
 */
  void MoveRight();
  void MoveLeft();
  void MoveUp();
  void MoveDown();
  void BackToHallway();
  /**
  * @brief Item Interaction functions
  * @param[in] value representing the string option for item
  * @throw errMessage If input is not one of the accepted values
  */
  void Drop(std::string itemName, int spot);
  void PickUp(std::string itemName, int spot);
  Hallway* currentHallway;
  StoryRoom* currentStoryRoom;
  Player* player;
  Room* GetCurrentRoom() const;
  Hallway* GetCurrentHallway() const;
};
#endif //GAMESTATE_H_INCLUDED
