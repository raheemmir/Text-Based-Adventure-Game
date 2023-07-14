#include "Item.h"
#include "KeepRunning.h"
//Constructor for any item that takes in a name and a descrption
Item::Item(std::string name, std::string description) {
  _name = name;
  _description = description;
}
//Returns the name of the item
std::string Item::getName() {
  return _name;
}
//Returns the descrption of the item
std::string Item::getDescription() {
  return _description;
}
//Checks if the user is in the right room to use an item,
//then reurns the correct string for the correct outcome
std::string Item::UseItem(std::string roomName) {
  if ((roomName == "Wardens Office") && (this->getName() == "Key")) {
    keep_running = false;
    return "You unlock the door in the warden's office and escape!";
  } else if ((roomName == "Starting Cell") && (this->getName() == "Lockpick")) {
    return "You start to lockpick your cell door...";
  } else if ((roomName == "Courtyard") && (this->getName() == "Shovel")) {
    keep_running = false;
    return "You dig a tunnel in the courtyard and escape!";
  } else if ((roomName == "Starting Cell") && (this->getName() == "pickaxe")) {
    keep_running = false;
    return "You break through a weak wall in your cell and escape!";
  } else {
    return "You can't use this item here.";
  }
}
