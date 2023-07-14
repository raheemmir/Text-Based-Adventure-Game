#include "GameState.h"
#include "Room.h"
#include "Player.h"
#include <vector>
#include <string>
#include <iostream>
//changes the value of game state to the hallway
//connected to the current room
void GameState::BackToHallway() {
  if (currentStoryRoom != nullptr) {
    std::cout << "Moving to the hallway..." << std::endl;
    currentHallway = currentStoryRoom->_hallway;
    currentStoryRoom = nullptr;
    std::cout << "Welcome to " << currentHallway->GetName() << std::endl;
    std::cout << currentHallway->GetDescription() << std::endl;
    std::cout << std::endl;
  } else {
    std::cout << "There is no hallway to move to." << std::endl;
  }
}
//Moves the game state room value to the right room connected
//to the hallway
void GameState::MoveRight() {
  if (currentHallway != nullptr) {
    std::cout << "Moving to the room on the right..." << std::endl;
    if (currentHallway->_right->isHallway()) {
      currentHallway = static_cast<Hallway*>(currentHallway->_right);
      std::cout << "Welcome to " << currentHallway->GetName() << std::endl;
      std::cout << currentHallway->GetDescription() << std::endl;
      std::cout << std::endl;
    } else {
      currentStoryRoom = static_cast<StoryRoom*>(currentHallway->_right);
      currentHallway = nullptr;
      std::cout << "Welcome to " << currentStoryRoom->GetName() << std::endl;
      std::cout << currentStoryRoom->GetDescription() << std::endl;
      std::cout << std::endl;
    }
  } else {
    std::cout << "There is no room on the right." << std::endl;
  }
}
//Moves the game state room value to the left room connected
//to the hallway
void GameState::MoveLeft() {
  if (currentHallway != nullptr) {
    std::cout << "Moving to the room on the left..." << std::endl;
    if (currentHallway->_left->isHallway()) {
      currentHallway = static_cast<Hallway*>(currentHallway->_left);
      std::cout << "Welcome to " << currentHallway->GetName() << std::endl;
      std::cout << currentHallway->GetDescription() << std::endl;
      std::cout << std::endl;
    } else {
      currentStoryRoom = static_cast<StoryRoom*>(currentHallway->_left);
      currentHallway = nullptr;
      std::cout << "Welcome to " << currentStoryRoom->GetName() << std::endl;
      std::cout << currentStoryRoom->GetDescription() << std::endl;
      std::cout << std::endl;
    }
  } else {
    std::cout << "There is no room on the left." << std::endl;
  }
}
//Moves the game state room value to the above room connected
//to the hallway
void GameState::MoveUp() {
  if (currentHallway != nullptr) {
    std::cout << "Moving to the room above..." << std::endl;
    if (currentHallway->_up->isHallway()) {
      currentHallway = static_cast<Hallway*>(currentHallway->_up);
      std::cout << "Welcome to " << currentHallway->GetName() << std::endl;
      std::cout << currentHallway->GetDescription() << std::endl;
      std::cout << std::endl;
    } else {
      currentStoryRoom = static_cast<StoryRoom*>(currentHallway->_up);
      currentHallway = nullptr;
      std::cout << "Welcome to " << currentStoryRoom->GetName() << std::endl;
      std::cout << currentStoryRoom->GetDescription() << std::endl;
      std::cout << std::endl;
    }
  } else {
    std::cout << "There is no room above you." << std::endl;
  }
}
//Moves the game state room value to the room bellow connected
//to the hallway
void GameState::MoveDown() {
  if (currentHallway != nullptr) {
    std::cout << "Moving to the room below..." << std::endl;
    if (currentHallway->_down->isHallway()) {
      currentHallway = static_cast<Hallway*>(currentHallway->_down);
      std::cout << "Welcome to " << currentHallway->GetName() << std::endl;
      std::cout << currentHallway->GetDescription() << std::endl;
      std::cout << std::endl;
    } else {
      currentStoryRoom = static_cast<StoryRoom*>(currentHallway->_down);
      currentHallway = nullptr;
      std::cout << "Welcome to " << currentStoryRoom->GetName() << std::endl;
      std::cout << currentStoryRoom->GetDescription() << std::endl;
      std::cout << std::endl;
    }
  } else {
    std::cout << "There is no room below you." << std::endl;
  }
}
//Takes an item out of the players inventory and puts it in the rooms
//inventory
void GameState::Drop(std::string itemName, int spot) {
  currentStoryRoom->_items.push_back(player->items[spot]);
  player->items.erase(player->items.begin() + spot);
  std::cout << "You dropped " << itemName << " in the "
      << currentStoryRoom->_name << "." << std::endl;
}
//Takes an item out of the room inventory and puts it into the
//players inventory
void GameState::PickUp(std::string itemName, int spot) {
  player->items.push_back(currentStoryRoom->_items[spot]);
  currentStoryRoom->_items.erase(currentStoryRoom->_items.begin() + spot);
  std::cout << "You picked up the " << itemName << " from the "
      << currentStoryRoom->_name << "." << std::endl;
}
//Returns the current room pointer
Room* GameState::GetCurrentRoom() const {
  if (currentStoryRoom != nullptr) {
    return currentStoryRoom;
  } else {
    return nullptr;
  }
}
//Returns the current hallway pointer
Hallway* GameState::GetCurrentHallway() const {
  if (currentHallway != nullptr) {
    return currentHallway;
  } else {
    return nullptr;
  }
}
