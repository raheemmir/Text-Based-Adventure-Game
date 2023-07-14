#include "ItemLogic.h"
#include "GameState.h"
#include "Puzzels.h"
#include "KeepRunning.h"
#include <iostream>
//Handles the current context of the game state to output the incorrect
//options related to items that the user can pick from
void ItemLogic::ItemOptions(GameState g) {
  std::cout << "1.) Interact with your items." << std::endl;
  std::cout << "2.) Interact with room items." << std::endl;
  int choice;
  std::cin >> choice;
  if (choice == 1) {
    if (g.player->items.size() > 0) {
      std::cout << "Which item do you want to interact with?" << std::endl;
      g.player->getItems();
      std::string itemChoice;
      std::cin >> itemChoice;
      if (itemChoice == "Shovel") {
        std::cout << "1.) Use item." << std::endl;
        std::cout << "2.) Drop item." << std::endl;
        int temp;
        std::cin >> temp;
        if (temp == 1) {
          std::vector<Item>::iterator it;
          for (it = g.player->items.begin(); it < g.player->items.end(); ++it) {
            if (it->getName() == "Shovel") {
              if (g.currentStoryRoom != nullptr) {
                std::cout << it->UseItem(g.currentStoryRoom->GetName())
                    << std::endl;
              } else {
                std::cout << it->UseItem(g.currentHallway->GetName())
                    << std::endl;
              }
            }
          }
        } else if (temp == 2) {
          int i;
          for (i = 0; i < g.player->items.size(); i++) {
            if (g.player->items[i].getName() == "Shovel") {
              if (g.currentStoryRoom != nullptr) {
                g.Drop("Shovel", i);
              } else {
                std::cout << "You are currently in a hallway"
                    << "and you cannot dorp and item here." << std::endl;
              }
            }
          }
        } else {
          std::cout << "You input an incorrect input." << std::endl;
        }
      } else if (itemChoice == "Key") {
        std::cout << "1.) Use item." << std::endl;
        std::cout << "2.) Drop item." << std::endl;
        int temp;
        std::cin >> temp;
        if (temp == 1) {
          std::vector<Item>::iterator it;
          for (it = g.player->items.begin(); it < g.player->items.end(); ++it) {
            if (it->getName() == "Key") {
              if (g.currentStoryRoom != nullptr) {
                std::cout << it->UseItem(g.currentStoryRoom->GetName())
                    << std::endl;
              } else {
                std::cout << it->UseItem(g.currentHallway->GetName())
                    << std::endl;
              }
            }
          }
        } else if (temp == 2) {
          int i;
          for (i = 0; i < g.player->items.size(); i++) {
            if (g.player->items[i].getName() == "Key") {
              if (g.currentStoryRoom != nullptr) {
                g.Drop("Key", i);
              } else {
                std::cout << "You are currently in a hallway"
                    << "and you cannot dorp and item here." << std::endl;
              }
            }
          }
        } else {
          std::cout << "You input an incorrect input." << std::endl;
        }
      } else if (itemChoice == "pickaxe") {
        std::cout << "1.) Use item." << std::endl;
        std::cout << "2.) Drop item." << std::endl;
        int temp;
        std::cin >> temp;
        if (temp == 1) {
          std::vector<Item>::iterator it;
          for (it = g.player->items.begin(); it < g.player->items.end(); ++it) {
            if (it->getName() == "pickaxe") {
              if (g.currentStoryRoom != nullptr) {
                std::cout << it->UseItem(g.currentStoryRoom->GetName())
                    << std::endl;
              } else {
                std::cout << it->UseItem(g.currentHallway->GetName())
                    << std::endl;
              }
            }
          }
        } else if (temp == 2) {
          int i;
          for (i = 0; i < g.player->items.size(); i++) {
            if (g.player->items[i].getName() == "pickaxe") {
              if (g.currentStoryRoom != nullptr) {
                g.Drop("pickaxe", i);
              } else {
                std::cout << "You are currently in a hallway"
                    << "and you cannot dorp and item here." << std::endl;
              }
            }
          }
        } else {
          std::cout << "You input an incorrect input." << std::endl;
        }
      } else if (itemChoice == "Lockpick") {
        std::cout << "1.) Use item." << std::endl;
        std::cout << "2.) Drop item." << std::endl;
        int temp;
        std::cin >> temp;
        if (temp == 1) {
          std::vector<Item>::iterator it;
          for (it = g.player->items.begin(); it < g.player->items.end(); ++it) {
            if (it->getName() == "Lockpick") {
              if (g.currentStoryRoom != nullptr) {
                std::cout << it->UseItem(g.currentStoryRoom->GetName())
                    << std::endl;
                Puzzel p;
                p.playLockPicking();
                if (p.gameWon() == true) {
                  g.currentStoryRoom->isLocked = false;
                } else {
                  std::cout
                  << "You failed to pick the lock and it broke"
                  << ", now you can't get out."
                  << std::endl;
                  keep_running = false;
                }
              } else {
                std::cout << it->UseItem(g.currentHallway->GetName())
                    << std::endl;
              }
            }
          }
        } else if (temp == 2) {
          int i;
          for (i = 0; i < g.player->items.size(); i++) {
            if (g.player->items[i].getName() == "Lockpick") {
              if (g.currentStoryRoom != nullptr) {
                g.Drop("Lockpick", i);
              } else {
                std::cout << "You are currently in a hallway"
                    << "and you cannot dorp and item here." << std::endl;
              }
            }
          }
        } else {
          std::cout << "You input an incorrect input." << std::endl;
        }
      } else {
        std::cout << "You input an incorrect input." << std::endl;
      }
    } else {
      std::cout << "You don't have any items." << std::endl;
    }
  } else if (choice == 2) {
    if (g.currentStoryRoom != nullptr
        && g.currentStoryRoom->GetInventory() == true) {
      std::cout << "Do you want to pick up the "
          << g.currentStoryRoom->_items[0].getName() << "? (y/n)" << std::endl;
      std::string temp;
      std::cin >> temp;
      if (temp == "y") {
        g.PickUp(g.currentStoryRoom->_items[0].getName(), 0);
      } else {
        std::cout << "You input an incorrect input." << std::endl;
      }
    }
  } else {
    std::cout << "You input an incorrect input." << std::endl;
  }
}
