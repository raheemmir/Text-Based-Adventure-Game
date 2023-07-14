#ifndef PUZZEL_H_INCLUDED
#define PUZZEL_H_INCLUDED
#include <random>

/**
 * @class Puzzel Puzzel.h "Puzzel.h"
 * @brief Abstract base class for Puzzel.
 */
class Puzzel {
 public:
  /**
   * @brief Sees if the user wins the puzzle
   */
  bool gameWon();
  /**
   * @brief The games the user may have to play through game
   */
  void playLockPicking();
  bool play_round(int lower_bound, int upper_bound, int allowed_mistakes,
                  int round);
  void playBlackJack();
  void playTrivia();
 protected:
  bool gameWin;
};
#endif

