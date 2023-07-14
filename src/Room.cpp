#include "Room.h"
#include "NonPlayerCharacter.h"
//Bool for checking if the room is a hallway for a hallway
bool Hallway::isHallway() {
  return true;
}
//Bool for checking if the room is a halllway for the story room
bool StoryRoom::isHallway() {
  return false;
}
//returns the name of the room
std::string Room::GetName() {
  return _name;
}
//returns the description of the room
std::string Room::GetDescription() {
  return _description;
}
//Checks if the room has items in its inventory
bool StoryRoom::GetInventory() {
  if (_items.size() > 0) {
    return true;
  } else {
    return false;
  }
}
//adds an npc to the room
void StoryRoom::AddNPC(NonPlayerCharacter npc) {
  _npc.push_back(npc);
}
//adds a npc to the hallway
void Hallway::AddNPC(NonPlayerCharacter npc) {
  _npc.push_back(npc);
}
//constructor for a hallway that takes in the Name
//and the description
Hallway::Hallway(std::string name, std::string description) {
  _name = name;
  _description = description;
  _left = nullptr;
  _right = nullptr;
  _up = nullptr;
  _down = nullptr;
}
//Checks if there is a guard npc in the hallway
bool Hallway::GuardPresent() {
  for (auto& npc : _npc) {
    if (npc.GetName() == "Guard") {
      return true;
    }
  }
  return false;
}

//Hallway 1 constructor
Hallway1::Hallway1() : Hallway("Hallway 1",
 "This is the first hallway in the prison") {
}
//Hallway 2 constructor
Hallway2::Hallway2() : Hallway("Hallway 2",
 "This is the second hallway in the prison") {
  //Guard guard1;
  //AddNPC(guard1);
}

//Hallway 3 constructor
Hallway3::Hallway3() : Hallway("Hallway 3",
 "This is the third hallway in the prison") {
}

//constructor for the courtyard room
Courtyard::Courtyard() {
  _name = "Courtyard";
  _description = "This is where the inmates go for some fresh air, the dirt "
  "seems really soft.";
  isLocked = false;
  _hallway = nullptr;

  KermitTheFrog kermitTheFrog;
  AddNPC(kermitTheFrog);
}
//constructor for the cafeteria room
Cafeteria::Cafeteria() {
  _name = "Cafeteria";
  _description =
      "This is where the inmates go to eat food, smells really good today.";
  isLocked = false;
  _hallway = nullptr;

  JordanPeterson jordanPeterson;
  AddNPC(jordanPeterson);
}
//constructor for the starting cell room
StartingCell::StartingCell() {
  _name = "Starting Cell";
  _description = "This is the cell you wake up in.";
  Item lockpick("Lockpick", "");
  _items.push_back(lockpick);
  _npc = std::vector<NonPlayerCharacter>();
  isLocked = true;
  _hallway = nullptr;
  Shahadat shahadat;
  AddNPC(shahadat);
}
//constructor for the gallows room
Gallows::Gallows() {
  _name = "Gallows";
  _description = "This is where the inmates are hung.";
  isLocked = false;
  Item shovel("Shovel", "");
  _items.push_back(shovel);
  _hallway = nullptr;
}
//constructor for the wardens office room
WardensOffice::WardensOffice() {
  _name = "Wardens Office";
  _description = "This is where the warden works."
  " The door could be unlocked with the right key.";
  isLocked = false;
  _hallway = nullptr;
}
//constructor for the showers room
Showers::Showers() {
  _name = "Showers";
  _description = "This is where the inmates go to shower.";
  isLocked = false;
  Item key("Key", "");
  _items.push_back(key);
  _hallway = nullptr;
}
//constructor for the labour camp room
LabourCamp::LabourCamp() {
  _name = "Labour Camp";
  _description = "This is where the inmates go to work.";
  isLocked = false;
  Item pickaxe("pickaxe", "");
  _items.push_back(pickaxe);
  _hallway = nullptr;
}
//constructor for the generic cell room
Cell::Cell() {
  _name = "Cell";
  _description = "This is where more of the inmates sleep.";
  isLocked = false;
  _hallway = nullptr;
  Nicole nicole;
  AddNPC(nicole);
}
