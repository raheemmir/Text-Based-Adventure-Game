#include "MapGenerator.h"
#include "Room.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cmath>
#include <iostream>

//Sets up the game map in the correct order
StoryRoom* MapGen::GenerateMap() {
  hallway1 = new Hallway1();
  hallway2 = new Hallway2();
  hallway3 = new Hallway3();

  R1 = new Courtyard();
  R2 = new Cafeteria();
  R3 = new StartingCell();
  R4 = new Gallows();
  R5 = new WardensOffice();
  R6 = new Showers();
  R7 = new Cell();
  R8 = new LabourCamp();
  hallway1->_right = hallway2;
  hallway2->_left = hallway1;
  hallway2->_right = hallway3;
  hallway3->_left = hallway2;
  rooms = { R1, R2, R3, R4, R5, R6, R7, R8 };
  //std::random_device rd;
  //std::mt19937 g(rd());
  //shuffle(rooms.begin(), rooms.end(), g);
  hallway1->_down = rooms[0];
  rooms[0]->_hallway = hallway1;
  hallway2->_down = rooms[1];
  rooms[1]->_hallway = hallway2;
  hallway3->_down = rooms[2];
  rooms[2]->_hallway = hallway3;
  hallway1->_up = rooms[3];
  rooms[3]->_hallway = hallway1;
  hallway2->_up = rooms[4];
  rooms[4]->_hallway = hallway2;
  hallway3->_up = rooms[5];
  rooms[5]->_hallway = hallway3;
  hallway1->_left = rooms[6];
  rooms[6]->_hallway = hallway1;
  hallway3->_right = rooms[7];
  rooms[7]->_hallway = hallway3;
  return R3;
}
//Outputs the map in a visual way so the user knows where they are
void MapGen::DisplayMap() {
  const int columnWidth = 13;

  int h1_center = (columnWidth - hallway1->_name.length()) / 2;
  int h2_center = (columnWidth - hallway2->_name.length()) / 2;
  int h3_center = (columnWidth - hallway3->_name.length()) / 2;

  std::cout << std::setw(columnWidth - h1_center + 3) << rooms[3]->_name
      << std::setw(columnWidth + h2_center + h1_center + 5) << rooms[4]->_name
      << std::setw(columnWidth + h3_center + h2_center)
      << rooms[5]->_name << std::endl;

  std::cout << std::setw(columnWidth - h1_center) << "|"
      << std::setw(columnWidth + h2_center + h1_center + 2) << "|"
      << std::setw(columnWidth + h3_center + h2_center + 2) << "|" << std::endl;

  std::cout << rooms[6]->_name << "--"
      << hallway1->_name << std::setw(columnWidth - 3) << "---"
      << hallway2->_name << std::setw(columnWidth - 3) << "---"
      << hallway3->_name
      << "--" << rooms[7]->_name << std::endl;

      std::cout << std::setw(columnWidth - h1_center) << "|"
          << std::setw(columnWidth + h2_center + h1_center + 2) << "|"
          << std::setw(columnWidth + h3_center + h2_center + 2)
          << "|" << std::endl;

  std::cout << std::setw(columnWidth - h1_center + 3) << rooms[0]->_name
      << std::setw(columnWidth + h2_center + h1_center + 2) <<
      rooms[1]->_name
      << std::setw(columnWidth + h3_center + h2_center + 3)
      << rooms[2]->_name << std::endl;
}
//Deletes the allocated memory from the map generation
void MapGen::Deallocate() {
  for (int i = 0; i < rooms.size(); ++i) {
    delete rooms[i];
  }
  rooms.clear();
  delete hallway1;
  delete hallway2;
  delete hallway3;
}
