#include "Gameplay.h"
#include <iostream>

int main() {
std::cout << "Welcome to Prison Break! Aria edition." << std::endl;
std::cout << std::endl << "You are the heir to the throne of Denmark. ";
std::cout << "The Current King Alexey has imprisoned you for treason" <<
" against the throne" << std::endl;
std::cout << "You have been sentenced to death and your execution is pending";
std::cout << std::endl << "You will Not stand for this blasphemy!" << std::endl;
std::cout << "You must break out of this prison and "
    << "rightfully claim what is yours!"
    << std::endl << std::endl << std::endl;

MapGen map;
StoryRoom *r = map.GenerateMap();
GameState state;
state.player = new Player();
state.currentStoryRoom = r;
state.currentHallway = nullptr;
Gameplay G;
G.GameLoop(&state, & map);
delete state.player;
  return 0;
}
