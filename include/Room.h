#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "NonPlayerCharacter.h"
#include "Item.h"
#include <vector>
#include <string>

/**
 * @class Room Room.h "Room.h"
 * @brief Abstract base class for Room.
 */
class Room {
 public:
  std::string GetName();
  std::string GetDescription();
  virtual bool isHallway() {
    return false;
  }
  std::string _name;
  std::string _description;
};

/**
 * @brief Rooms classified as Hallways
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them
 */
class Hallway : public Room {
 public:
  Hallway(std::string name, std::string description);
  bool isHallway() override;
  Room *_left;
  Room *_right;
  Room *_up;
  Room *_down;
  bool GuardPresent();
  void AddNPC(NonPlayerCharacter npc);
  std::vector<NonPlayerCharacter> _npc;
};

/**
 * @brief Room classified as Hallway1
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them
 */
class Hallway1 : public Hallway {
 public:
  Hallway1();
};

/**
 * @brief Room classified as Hallway2
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them
 */
class Hallway2 : public Hallway {
 public:
  Hallway2();
};

/**
 * @brief Room classified as Hallway3
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them
 */
class Hallway3 : public Hallway {
 public:
  Hallway3();
};

/**
 * @brief Rooms classified as StoryRooms
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class StoryRoom : public Room {
 public:
  bool isLocked;
  bool isHallway();
  bool GetInventory();
  std::vector<Item> _items;
  std::vector<NonPlayerCharacter> _npc;
  Hallway *_hallway;

  void AddNPC(NonPlayerCharacter npc);
};

/**
 * @brief Room classified as Courtyard
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class Courtyard : public StoryRoom {
 public:
  Courtyard();
};

/**
 * @brief Room classified as Cafeteria
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class Cafeteria : public StoryRoom {
 public:
  Cafeteria();
};

/**
 * @brief Room classified as StartingCell
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class StartingCell : public StoryRoom {
 public:
  StartingCell();
};

/**
 * @brief Room classified as Gallows
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class Gallows : public StoryRoom {
 public:
  Gallows();
};

/**
 * @brief Room classified as WardensOffice
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class WardensOffice : public StoryRoom {
 public:
  WardensOffice();
};

/**
 * @brief Room classified as Showers
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class Showers : public StoryRoom {
 public:
  Showers();
};

/**
 * @brief Room classified as LabourCamp
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class LabourCamp : public StoryRoom {
 public:
  LabourCamp();
};

/**
 * @brief Room classified as Cell
 * @details Return the string of the room name and lets the player
 * interact with the room by moving through them and interacting
 * with items in the room if there are any, or using the item in
 * the room and any NPC that is in the room
 */
class Cell : public StoryRoom {
 public:
  Cell();
};
#endif //ROOM_H_INCLUDED
