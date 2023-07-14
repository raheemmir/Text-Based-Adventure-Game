#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>

/**
* @class Item Item.h "Item.h" 
* @brief Abstract base class for item
*/
class Item {
 public:
 /**
 * @brief Item constructor, taking item name and description
 * as strings.
 */
  Item(std::string name, std::string description);
 /**
 * @brief Get item name.
 * @return The items name.
 */
  std::string getName();
 /**
 * @brief Get item description.
 * @return a brief description of item and its use.
 */
  std::string getDescription();
 /**
 * @brief Using the item
 * @details Takes the item name and returns the name of the room it is usuable in
 * @return Item use and room it is usable in
 */
  std::string UseItem(std::string roomName);

 private:
  std::string _name;
  std::string _description;
};

#endif //ITEM_H_INCLUDED
