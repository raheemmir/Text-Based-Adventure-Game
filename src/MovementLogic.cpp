#include <vector>
#include <string>
#include "MovementLogic.h"
//Handles the current context of the game state to output the incorrect
//options related to movement that the user can pick from
void MovementLogic::MovementOptions(GameState* g) {
  std::string moveChoice;
  if (g->currentStoryRoom != nullptr) {
    std::cout << "Move to hallway (y/n)." << std::endl;
    std::cin >> moveChoice;
    if (moveChoice == "y" && g->currentStoryRoom->isLocked == true) {
      std::cout << "You can't leave this room,"<<
       "the door is locked." << std::endl;
    } else if (moveChoice == "y" && g->currentStoryRoom->isLocked != true) {
      g->BackToHallway();
    } else if (moveChoice == "n") {
      //exits out of the function
      return;
    } else {
      std::cout << "invalid input." << std::endl;
    }
  }
  if (g->currentHallway != nullptr) {
    std::cout << "1. Move Left" << std::endl;
    std::cout << "2. Move Right" << std::endl;
    std::cout << "3. Move Up" << std::endl;
    std::cout << "4. Move Down" << std::endl;
    std::cin >> moveChoice;
    if (moveChoice == "1") {
        g->MoveLeft();
    } else if (moveChoice == "2") {
        g->MoveRight();
    } else if (moveChoice == "3") {
        g->MoveUp();
    } else if (moveChoice == "4") {
        g->MoveDown();
    } else {
      std::cout << "invalid input." << std::endl;
    }
    if (g->currentHallway != nullptr && g->currentHallway->GuardPresent()) {
      std::cout << "There is a guard in this hallway!"<<
      "You have been caught!" << std::endl;
      exit(0); // Exit the game
    }
  }
}
