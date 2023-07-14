#include "NPCLogic.h"
#include "GameState.h"
#include <iostream>
#include <vector>
#include <string>
//Handles the current context of the game state to output the incorrect
//options related to NPCs that the user can pick from
void NPCLogic::NPCOptions(GameState g) {
  Room* currentRoom = g.GetCurrentRoom();
  std::vector<NonPlayerCharacter>* npcList;

  if (currentRoom->isHallway()) {
    Hallway* hallway = static_cast<Hallway*>(currentRoom);
    npcList = &hallway->_npc;
  } else {
    StoryRoom* storyRoom = static_cast<StoryRoom*>(currentRoom);
    npcList = &storyRoom->_npc;
  }

  if (npcList->empty()) {
    std::cout << "There are no characters in this room." << std::endl;
  } else {
    std::cout << "Which character would"<<
     "you like to interact with?" << std::endl;
    int i = 1;
    for (auto& npc : *npcList) {
      std::cout << i << ". " << npc.GetName() << std::endl;
      ++i;
    }

    int choice;
    std::cin >> choice;

    // Changed the condition to check
    // npcList size instead of g.currentStoryRoom->_npc.size()
    if (choice > 0 && choice <= npcList->size()) {
      auto& npc = (*npcList)[choice - 1];
      std::cout << "Interacting with " << npc.GetName() << ": " << std::endl;

      if (npc.GetName() == "Shahadat") {
        NonPlayerCharacter* n = new Shahadat();
        std::cout << n->Interact() << std::endl;
        delete n;
      } else if (npc.GetName() == "Guard") {
        NonPlayerCharacter* n = new Guard();
        std::cout << n->Interact() << std::endl;
        delete n;
      } else if (npc.GetName() == "Nicole") {
        NonPlayerCharacter* n = new Nicole();
        std::cout << n->Interact() << std::endl;
        delete n;
      } else if (npc.GetName() == "KermitTheFrog") {
        NonPlayerCharacter* n = new KermitTheFrog();
        std::cout << n->Interact() << std::endl;
        delete n;
      } else if (npc.GetName() == "JordanPeterson") {
        NonPlayerCharacter* n = new JordanPeterson();
        std::cout << n->Interact() << std::endl;
        delete n;
      }
    } else {
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }
}
