#include "Logic.h"

/**
* @class Gameplay Gameplay.h "Gameplay.h"
* @brief A gameloop method that runs the game
*/
class Gameplay {
 public:
 /**
 * @brief GameLoop function, uses Gamestate and Mapgen
 */
  void GameLoop(GameState* state, MapGen* map);
};
