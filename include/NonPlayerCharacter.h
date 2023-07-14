#ifndef NONPLAYERCHARACTER_H_INCLUDED
#define NONPLAYERCHARACTER_H_INCLUDED

#include <string>

/**
 * @class NonPlayerCharacter NonPlayerCharacter.h "NonPlayerCharacter.h"
 * @brief Abstract base class for NonPlayerCharacter.
 */
class NonPlayerCharacter {
 public:
  /**
   * @brief NonPlayerCharacter name
   * @details Return the string of the character name
   */
  NonPlayerCharacter(std::string name);
  std::string GetName();
  virtual std::string Interact() {
    return "";
  }

 protected:
  std::string _name;
};

/**
 * @brief NonPlayerCharacter named Guard
 * @details Return the string of the character name and lets the player
 * interact with the NPC
 */
class Guard : public NonPlayerCharacter {
 public:
  Guard();
  std::string Interact() override;
};

/**
 * @brief NonPlayerCharacter named Shahadat
 * @details Return the string of the character name and lets the player
 * interact with the NPC
 */
class Shahadat : public NonPlayerCharacter {
 public:
  Shahadat();
  std::string Interact() override;
};

/**
 * @brief NonPlayerCharacter named Nicole
 * @details Return the string of the character name and lets the player
 * interact with the NPC
 */
class Nicole : public NonPlayerCharacter {
 public:
  Nicole();
  std::string Interact() override;
};

/**
 * @brief NonPlayerCharacter named KermitTheFrog
 * @details Return the string of the character name and lets the player
 * interact with the NPC
 */
class KermitTheFrog : public NonPlayerCharacter {
 public:
  KermitTheFrog();
  std::string Interact() override;
};

/**
 * @brief NonPlayerCharacter named JordanPeterson
 * @details Return the string of the character name and lets the player
 * interact with the NPC
 */
class JordanPeterson : public NonPlayerCharacter {
 public:
  JordanPeterson();
  std::string Interact() override;
};

#endif // NONPLAYERCHARACTER_H_INCLUDED

