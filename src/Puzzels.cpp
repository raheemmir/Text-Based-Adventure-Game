#include "Puzzels.h"
#include <iostream>
#include <random>
//Returns true when you won the game
bool Puzzel::gameWon() { return gameWin; }

// lockPicking::lockPicking() { gameWin = false; }
bool Puzzel::play_round(int lower_bound, int upper_bound, int allowed_mistakes,
                        int round) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(lower_bound, upper_bound);

  int secret_number = dist(gen);
  int num_guesses = 0;
  int guess;

  while (num_guesses < allowed_mistakes) {
    std::cout << "Round " << round << " Guess a number between " << lower_bound
              << " and " << upper_bound << ": ";
    std::cout << secret_number << std::endl;
    std::cin >> guess;

    if (guess == secret_number) {
      return true;
    } else {
      num_guesses++;
    }
  }

  return false;
}
//Starts the lockpick game
void Puzzel::playLockPicking() {
  gameWin = false;
  // Play the first round
  if (play_round(1, 3, 1, 1)) {
    std::cout << "You have successfully picked the  of the first round: "
              << std::endl;
  } else {
    gameWin = false;
    return;
  }

  // Play the second round
  if (play_round(4, 10, 2, 2)) {
    std::cout << "You have successfully picked the lock of the second round: "
              << std::endl;
  } else {
    gameWin = false;
    return;
  }

  // Play the third round
  if (play_round(11, 20, 3, 3)) {
    std::cout << "You have successfully picked the lock of the third round: "
              << std::endl
              << std::endl;
    gameWin = true;
  } else {
    gameWin = false;
    return;
  }
}
//Starts the Black Jack game
void Puzzel::playBlackJack() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(2, 10);
  int opponentStart = dist(gen);
  int playerStart = dist(gen);
  std::cout << "Here is my starting card " << opponentStart << std::endl;
  std::cout << "Here is your starting card " << playerStart << std::endl;

  int opponent = opponentStart;
  int player = playerStart;

  while (player <= 21 && opponent <= 21) {
    std::cout << "Do you want to 1.draw a new card or 2.hold " << std::endl;
    int choice;
    std::cin >> choice;

    if (choice == 1) {
      int playerNewCard = dist(gen);
      player += playerNewCard;
      std::cout << "You drew " << playerNewCard << std::endl;
      std::cout << "Your total is now " << player << std::endl;
    } else if (choice == 2) {
      break;
    }
  }

  if (player > 21) {
    std::cout << "You went over 21. I won" << std::endl;
    gameWin = false;
    return;
  }

  while (opponent < player && opponent <= 21) {
    int opponentNewCard = dist(gen);
    opponent += opponentNewCard;
    std::cout << "I drew " << opponentNewCard << std::endl;
    std::cout << "My total is now " << opponent << std::endl;
  }

  if (opponent > 21 || (player <= 21 && player > opponent)) {
    std::cout << "You won" << std::endl;
    gameWin = true;
  } else if (opponent <= 21 && opponent >= player) {
    std::cout << "I won" << std::endl;
    gameWin = false;
  } else {
    std::cout << "It's a draw you lose" << std::endl;
    gameWin = false;
  }
}
//Start the Trivia game
void Puzzel::playTrivia() {
  int answer;
  int correctAnswers = 0;
  // Question 1
  std::cout << "\nWhich Supreme Court case led to the legalization of racial "
  "segregation in the United States, laying the groundwork for "
"Jim Crow laws and widespread discrimination?\n"
"1. Plessy v. Ferguson\n"
"2. Brown v. Board of Education\n"
"3. Dred Scott v. Sandford\n"
"4. Loving v. Virginia\n";
  std::cin >> answer;
  if (answer == 1) {
    correctAnswers++;
    std::cout <<"You got it correct\n";
  } else {
    std::cout << "You lose. Better luck next time!" << std::endl;
    gameWin = false;
    return;
  }

  // Question 2
  std::cout<< "\nWhich historical event is"
   "considered to have been a significant "
"contributing factor to the racial wealth gap in the United States?\n"
"1. The Emancipation Proclamation\n"
"2. The GI Bill and post-WWII housing policies\n"
"3. The Civil Rights Act of 1964\n"
"4. The end of the Reconstruction era\n";
  std::cin >> answer;
  if (answer == 2) {
    correctAnswers++;
    std::cout <<"You got it correct\n";
  } else {
    std::cout << "You lose. Better luck next time!" << std::endl;
    gameWin = false;
    return;
  }

  // Question 3
  std::cout << "\nWhich of these social theories emphasizes the role of "
  "institutional structures and practices in perpetuating racial "
"inequality in the United States?\n"
"1. Structural racism\n"
"2. Intersectionality\n"
"3. Symbolic interactionism\n"
"4. Social Darwinism\n";
  std::cin >> answer;
  if (answer == 1) {
    correctAnswers++;
    std::cout <<"You got it correct\n";
  } else {
    std::cout << "You lose. Better luck next time!" << std::endl;
    return;
  }

  if (correctAnswers == 3) {
    std::cout << "Congratulations! You won!" << std::endl;
    gameWin = true;
  } else {
    std::cout << "You lose. Better luck next time!" << std::endl;
    gameWin = false;
  }
}
