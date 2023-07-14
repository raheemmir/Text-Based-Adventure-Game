#include "Player.h"
#include "Item.h"
#include <string>
#include <vector>
#include <iostream>
//Returns the name of the player character
std::string Player::getName() {
  return "2720Student";
}
//Lists the items in the players current inventory
void Player::getItems() {
  std::cout << "Here is your item(s):\n";
  std::vector<Item>::iterator it;
  for (it = items.begin(); it < items.end(); ++it) {
    std::cout << it->getName() << std::endl;
  }
}
