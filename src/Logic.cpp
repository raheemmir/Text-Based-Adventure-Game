#include "Logic.h"
#include "MovementLogic.h"
#include "NPCLogic.h"
#include "ItemLogic.h"
#include "MapGenerator.h"

void Logic::InputHandler(int choice, GameState* g, MapGen* map) {
ItemLogic iL;
MovementLogic mL;
NPCLogic npcL;
if (choice == 1) {
  mL.MovementOptions(g);
} else if (choice == 2 && g->currentHallway ==nullptr) {
  iL.ItemOptions(*g);
} else if (choice == 3 && g->currentHallway ==nullptr) {
  npcL.NPCOptions(*g);
} else if (choice == 4 && g->currentHallway ==nullptr) {
  map->DisplayMap();
  if (g->GetCurrentRoom() != nullptr) {
    std::cout << std::endl <<
    "You're currently in the "
    << g->GetCurrentRoom()->GetName() << std::endl;
  } else if (g->GetCurrentHallway() != nullptr) {
    std::cout << std::endl <<
    "You're currently in the "
    << g->GetCurrentHallway()->GetName() << std::endl;
  }
} else if (choice == 5) {
  EndGame(map);
}
}

void Logic::EndGame(MapGen* map) {
    std::cout << "Game Over: Thanks for playing!" << std::endl;
    map->Deallocate();  // Clean up resources if necessary
}
