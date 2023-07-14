#ifndef MAPGENERATOR_H_INCLUDED
#define MAPGENERATOR_H_INCLUDED

#include "Room.h"
#include <vector>
#include <cmath>
#include <random>

/**
 * @class MapGen MapGen.h "MapGen.h"
 * @brief Abstract base class for MapGen
 */
class MapGen {
 public:
  /**
   * @brief Generates the map and story rooms as user starts game
   * @details Generates the map, story rooms, and hallways, then deallocates
   * after the user moves between each room.
   */
  StoryRoom* GenerateMap();
  void DisplayMap();
  void Deallocate();
  StoryRoom *R1;
  StoryRoom *R2;
  StoryRoom *R3;
  StoryRoom *R4;
  StoryRoom *R5;
  StoryRoom *R6;
  StoryRoom *R7;
  StoryRoom *R8;
  Hallway *hallway1;
  Hallway *hallway2;
  Hallway *hallway3;
  std::vector<StoryRoom*> rooms;
};
#endif //MAPGENERATOR_H_INCLUDED
