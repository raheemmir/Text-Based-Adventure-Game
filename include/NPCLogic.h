#ifndef NPCLOGIC_H_INCLUDED
#define NPCLOGIC_H_INCLUDED

#include "GameState.h"

/**
 * @class NPCLogic NPCLogic.h "NPCLogic.h"
 * @brief Abstract base class for NPCLogic.
 */
class NPCLogic {
 public:
  /**
   * @brief Gives user options for interacting with NPCs
   * @details User is given different text options with the NPC's
   * altering the gamestate as they ask different questions
   */
  void NPCOptions(GameState g);
};
#endif //MOVEMENTLOGIC_H_INCLUDED
