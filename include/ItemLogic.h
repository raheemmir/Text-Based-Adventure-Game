#ifndef ITEMLOGIC_H_INCLUDED
#define ITEMLOGIC_H_INCLUDED

#include "GameState.h"

/**
 * @class ItemLogic ItenLogic.h "ItemLogic.h"
 * @brief Abstract base class of ItemLogic
 */
class ItemLogic {
 public:
/**
 * @brief Displays options for using items or not
 * @details Asks if the user wants to interact with room items or their own items
 */
  void ItemOptions(GameState g);
};
#endif //ITEMLOGIC_H_INCLUDED
