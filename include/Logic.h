#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED

#include "Room.h"
#include "MovementLogic.h"
#include "NPCLogic.h"
#include "MapGenerator.h"
#include "ItemLogic.h"
#include <vector>
#include <string>

/**
 * @class Logic Logic.h "Logic.h"
 * @brief Abstract base class for Logic
 */
class Logic {
 public:
  /**
   * @brief Takes the user input
   * @details Outputs the choices for the user and gives them certain options to input
   * and determines the next state of the game depending on the user input
   */
  void InputHandler(int choice, GameState *g, MapGen *map);

  /**
   * @brief Ends the Game for the user
   * @details using a pointer to mapgen the game is ended when either the user beats the
   * game or loses.
   */
  void EndGame(MapGen *map);
};
#endif //LOGIC_H_INCLUDED
