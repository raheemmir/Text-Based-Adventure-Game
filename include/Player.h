#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Item.h"
#include <string>
#include <vector>

/**
 * @class Player Player.h "Player.h"
 * @brief Abstract base class for Player.
 */
class Player {
 public:
  std::vector<Item> items;
  void getItems();
  std::string getName();
};
#endif //PLAYER_H_INCLUDED
