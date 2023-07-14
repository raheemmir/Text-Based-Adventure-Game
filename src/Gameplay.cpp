#include "Logic.h"
#include "Gameplay.h"
#include "MapGenerator.h"
#include "KeepRunning.h"
#include <string>

//Handles the input delegation from the user to the logic handler
void Gameplay::GameLoop(GameState* state, MapGen* map) {
  //call introduction output function (rules, introduction, story, text)
  //creating the map
  //ask to start game
  Logic l;
  Room* currentRoom = state->GetCurrentRoom();
  //Hallway* currentHallway = state->GetCurrentHallway();
  std::cout << "Your name:" << state->player->getName() << std::endl;
  std::cout << "You are currently in: " << currentRoom->GetName() << std::endl;
  int userChoice = 0;
  while (userChoice != 5 && keep_running == true) {
    if (state->currentHallway == nullptr) {
    std::cout << "Choose an Action: " << std::endl;
    std::cout << "1. Movement" << std::endl;
    std::cout << "2. Items" << std::endl;
    std::cout << "3. Character" << std::endl;
    std::cout << "4. display Map" << std::endl;
    std::cout << "5. End Game" << std::endl;
    std::cin >> userChoice;
    l.InputHandler(userChoice, state, map);
  } else {
    std::cout << "1. Movement" << std::endl;
    std::cout << "5. End Game" << std::endl;
    std::cin >> userChoice;
    l.InputHandler(userChoice, state, map);
    }
  }
  if (keep_running == false) {
    l.EndGame(map);
  }
}
