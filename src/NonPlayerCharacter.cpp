#include "Room.h"
#include "NonPlayerCharacter.h" // Add this line
#include "KeepRunning.h"
#include <string>
#include "Puzzels.h"
//Constructor for npc that takes in a string for the name
NonPlayerCharacter::NonPlayerCharacter(std::string name)
    :
    _name(name) {
}
//Returns the name of the character
std::string NonPlayerCharacter::GetName() {
  return _name;
}
//Constructor for the guard npc
Guard::Guard()
    :
    NonPlayerCharacter("Guard") {
}
//Interact function for the guard npc
std::string Guard::Interact() {
  return "Hey, you aren't supposed to be here!";
}
//constructor for the shahadat npc
Shahadat::Shahadat()
    :
    NonPlayerCharacter("Shahadat") {
}
//Interact function for the shahadat npc that encapsulates the
//loop for dialogue
std::string Shahadat::Interact() {
  int choice = 0;
  std::string ShadahatDialogue = "";

  while (choice != 5) {
    std::cout << "1. Where am i? " << std::endl;
    std::cout << "2. Why am i here? " << std::endl;
    std::cout << "3. Why are you here? " << std::endl;
    std::cout << "4. What should i do? " << std::endl;
    std::cout << "5. End conversation " << std::endl;
    std::cin >> choice;

    if (choice == 1) {
      ShadahatDialogue = "You are in your prison cell";
      std::cout << std::endl << ShadahatDialogue << std::endl << std::endl;
    } else if (choice == 2) {
      ShadahatDialogue =
          "You are in prison because the king placed you in here. "
              "You are the bastard son of King John, "
              "but after king Alexey kiled his brother, "
              "he imprisoned everybody that threatened his rule, "
              "and you are the only legitimate successor. "
              "You are the true heir of the throne of Denmark my lord";
      std::cout << std::endl << ShadahatDialogue << std::endl << std::endl;
    } else if (choice == 3) {
      ShadahatDialogue =
     "I used to be the close advisor for King John The Great, "
     "he was a great and a fair ruler. "
     "When King Alexey usurped the throne he saw me as a threat. "
     "So, he needed to get rid of me but he could not afford to kill me, "
     "since I have a lot supporters in his court.";
      std::cout << std::endl << ShadahatDialogue << std::endl << std::endl;
    } else if (choice == 4) {
      ShadahatDialogue =
     "YOU HAVE TO ESCAPE THIS PRISON, YOU ARE THE KINGDOMS ONLY HOPE. "
     "Go to Nicole she will tell you how to escape."
     "Pick up the LockPick that is in that corner "
     "and free your self from this cell, "
     "but be careful with the lock because if you fail to pick the lock, "
     "the guards will show up and they will execute you."
     "You will need the LockPick to enter a lot of rooms in the prison. "
              "Good luck!";
      std::cout << std::endl << ShadahatDialogue << std::endl << std::endl;
    } else if (choice == 5) {
      ShadahatDialogue = "Goodbye your highness...";
    } else {
      std::cout << "Wrong input:" << std::endl << std::endl;
    }
  }

  return ShadahatDialogue;
}
//Constructor for the nicole npc
Nicole::Nicole()
    :
    NonPlayerCharacter("Nicole") {
}
//Interact function for the nicole npc that encapsulates the
//loop for dialogue
std::string Nicole::Interact() {
  int choice = 0;
  std::string NicoleDialogue = "";

  while (choice != 5) {
    std::cout << "1. Who are you? " << std::endl;
    std::cout << "2. What are you doing here?" << std::endl;
    std::cout << "3. What do you want me to do?" << std::endl;
    std::cout << "4. Where do I find these items?" << std::endl;
    std::cout << "5. End conversation " << std::endl;
    std::cin >> choice;

    if (choice == 1) {
      NicoleDialogue =
          "My Name is Nicole, I am a friend of Shahadat and your father";
      std::cout << std::endl << NicoleDialogue << std::endl << std::endl;
    } else if (choice == 2) {
      NicoleDialogue =
      "Alongside Shahadat I was imprisoned by King Alexey after he realized "
      "I had a connection to the previous crown, and he gave me a choice, "
      "To swear my undying loyalty to the new crown, or be put to death. "
      "I have since then been imprisoned and am waiting for my execution "
      "date to be set.";
      std::cout << NicoleDialogue << std::endl << std::endl;
    } else if (choice == 3) {
      NicoleDialogue =
          "You must escape, from my time here I have seen there are 3 ways to "
              "escape this prison. "
              "1. You steal the wardens key "
              "and enter his office and escape through the window "
              "2. You find a shovel and dig out through the courtyard. "
              "3. You find a pickaxe and dig through the wall of your cell "
              "You must find one of these three items "
              "and use that item to escape this hellhole.";
      std::cout << std::endl << NicoleDialogue << std::endl << std::endl;
    } else if (choice == 4) {
      NicoleDialogue =
     "To find the wardens key, you must steal it from his clothes "
     "(probably while he showers). "
     "To find the shovel, you must find KermitTheFrog, hes usually in "
     "the courtyard hanging around there."
     "You may have to do something for him to get "
     "information on the shovel. "
     "Lastly, to find the pickaxe, you must find JordanPeterson, he is "
     "usually in the Cafeteria. "
     "And again, you may have do something for him to get "
     "information on the pickaxe.";
      std::cout << std::endl << NicoleDialogue << std::endl << std::endl;
    } else if (choice == 5) {
      NicoleDialogue = "Good luck in your journey, your highness.";
    } else {
      std::cout << "Wrong input:" << std::endl << std::endl;
    }
  }
  return NicoleDialogue;
}
//Constructor for the KermitTheFrog npc
KermitTheFrog::KermitTheFrog()
    :
    NonPlayerCharacter("KermitTheFrog") {
}
//Interact function for the KermitTheFrog npc that encapsulates the
//loop for dialogue
std::string KermitTheFrog::Interact() {
  int choice = 0;
  std::string KermitTheFrogDialogue = "";

  while (choice != 4) {
    std::cout << "1. Are you KermitTheFrog? " << std::endl;
    std::cout << "2. What are you doing here? Its me"
        "the true heir to the throne! " << std::endl;
    std::cout << "3. Could you tell me how i could escape from prison"
        << std::endl;
    std::cout << "4. Lets play" << std::endl;
    std::cout << "5. End conversation " << std::endl;
    std::cin >> choice;

    if (choice == 1) {
      KermitTheFrogDialogue = "Yes, who is asking. ";
      std::cout << std::endl << KermitTheFrogDialogue << std::endl << std::endl;
    } else if (choice == 2) {
      KermitTheFrogDialogue =
  "Why your asking. Oh its you! you're the heir to the thorone of Denmark."
  "I did not recongnize you! "
  "I am here because one day I saw a carousel that was full with gold, "
  "and I said to my self, KermitTheFrog this is your lucky day!"
  "I prepared myself to attack them and get the gold, "
  "but I was stopped by guards, "
  "and it turns out that the King was inside of the caravan.";
      std::cout << std::endl << KermitTheFrogDialogue << std::endl << std::endl;

    } else if (choice == 3) {
      KermitTheFrogDialogue =
          "I've been in prison for a long time, "
              "and I came up with a good game called Black Jack."
              "Why the name Black Jack? why not? "
              "So the rule of the game is we play with cards, "
              "and at the beginning of the game we both get a card, "
              "and you get a choice to either draw another card or hold."
              "If you hold I'm going to draw a card "
              "and if you hold and i get a card number that "
              "is bigger then yours you lose, "
              "but if I get less then you or more then 21 you win. "
              "If you beat me in Black Jack "
              "I will tell you how you could escape.";
      std::cout << KermitTheFrogDialogue << std::endl << std::endl;
    } else if (choice == 4) {
      KermitTheFrogDialogue = "Ok lets play the game. "
          "Oh I forgot to let you know if I beat you I will tell the guards "
          "that you are trying to escape. "
          "Good luck!";
      std::cout << std::endl << KermitTheFrogDialogue << std::endl << std::endl;
      Puzzel p;
      p.playBlackJack();
      if (p.gameWon() == true) {
        KermitTheFrogDialogue =
      "Ok Ok you win. you need a shovel, and you will find it in the gallows, "
      "and you can use it in the courtyard. "
      "guards do not come in the courtyard, "
      "so you will be good. Good luck your highness!";
        std::cout << std::endl << KermitTheFrogDialogue << std::endl
            << std::endl;
      } else if (p.gameWon() == false) {
        KermitTheFrogDialogue =
            "Ha Ha Ha you lose. GUARDS he is trying to escape!, (you lost)";
        std::cout << std::endl << KermitTheFrogDialogue << std::endl
            << std::endl;
        keep_running = false;
      }
    } else if (choice == 5) {
      KermitTheFrogDialogue = "Goodbye your highness...";
    } else {
      std::cout << "Wrong input:" << std::endl << std::endl;
    }
  }

  return KermitTheFrogDialogue;
}
//Constructor for the JordanPeterson npc
JordanPeterson::JordanPeterson()
    :
    NonPlayerCharacter("JordanPeterson") {
}
//Interact function for the JordanPeterson npc that encapsulates the
//loop for dialogue
std::string JordanPeterson::Interact() {
  int choice = 0;
  std::string JordanDialogue = "";

  while (choice != 5) {
    std::cout << "1. Are you Mr. Jordan Peterson? " << std::endl;
    std::cout << "2. Why are you in the prison? " << std::endl;
    std::cout << "3. Could you tell me how I can escape from this prison? "
        << std::endl;
    std::cout << "4. Hit me with the questions then! " << std::endl;
    std::cout << "5. End conversation " << std::endl;
    std::cin >> choice;

    if (choice == 1) {
      JordanDialogue = "I may be I may not be depends on who's asking?";
      std::cout << std::endl << JordanDialogue << std::endl;
    } else if (choice == 2) {
      JordanDialogue = "Oh! your highness, my apologies. "
      "I used to work as a builder for Anvik the warden,"
      " and one day i forgot to follow his design pattern,"
      " and when he found out, "
      "he sent a request to King Alexey his friend for my arrest,"
      " and he sentenced "
      "me to death. That crazy bastard!";
      std::cout << std::endl << JordanDialogue << std::endl;
    } else if (choice == 3) {
      JordanDialogue =
     "I could tell you but I dont fully trust you yet, youll have to "
     "answer a couple questions for me to make sure you are legitimate "
     "and ready to do whatever it takes to escape.";
      std::cout << std::endl << JordanDialogue << std::endl;
    } else if (choice == 4) {
      JordanDialogue =
          "Okay I have three quesions for you to answer, if you get them "
              "all right, I will tell you a way to escape. However, if you "
              "get ONE QUESTION wrong, I will report you to the guards and "
              "you will be executed. You have been warned, your highness.";
      std::cout << std::endl << JordanDialogue << std::endl;
      Puzzel p;
      p.playTrivia();
      if (p.gameWon() == true) {
        JordanDialogue = "Okay I believe in your abilities."
        "You can find a spare "
        "pickaxe in the labour camp just be careful that the "
        "guards are not in there. Good luck your higness I wish ";
        std::cout<< JordanDialogue << std::endl;
      } else if (p.gameWon() == false) {
        JordanDialogue =
        "Hmm, it would see you aren't as capable as you believe "
                    "you are, youre not worth my time. GUARDS!!!, (You lost)";
        keep_running = false;
    }
  } else if (choice == 5) {
      JordanDialogue = "Bye bye your highness...";
    } else {
      std::cout << "Wrong Input:" << std::endl << std::endl;
    }
  }
  return JordanDialogue;
}
