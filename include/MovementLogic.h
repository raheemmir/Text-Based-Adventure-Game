#ifndef MOVEMENTLOGIC_H_INCLUDED
#define MOVEMENTLOGIC_H_INCLUDED

#include "GameState.h"

/**
 * @class MovementLogic MovementLogic.h "MovementLogic.h"
 * @brief Abstract base class for MovementLogic.
 */
class MovementLogic {
 public:
  /**
   * @brief Displays movement options to user
   * @details Displays the options for moving to the user and updates the
   * gamestate pointer depending on their input
   */
  void MovementOptions(GameState *g);
};
#endif //MOVEMENTLOGIC_H_INCLUDED
