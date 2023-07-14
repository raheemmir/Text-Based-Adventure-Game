#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cmath>
#include <iostream>
#include "MapGenerator.h"
#include "GameState.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestMapGenerator, TestGenerateMap) {
  MapGen map;
  map.GenerateMap();
  EXPECT_EQ(map.R1->GetName(), "Courtyard");
  EXPECT_EQ(map.R2->GetName(), "Cafeteria");
  EXPECT_EQ(map.R3->GetName(), "Starting Cell");
  EXPECT_EQ(map.R4->GetName(), "Gallows");
  EXPECT_EQ(map.R5->GetName(), "Wardens Office");
  EXPECT_EQ(map.R6->GetName(), "Showers");
  EXPECT_EQ(map.R7->GetName(), "Cell");
  EXPECT_EQ(map.R8->GetName(), "Labour Camp");
  EXPECT_EQ(map.hallway1->GetName(), "Hallway 1");
  EXPECT_EQ(map.hallway2->GetName(), "Hallway 2");
  EXPECT_EQ(map.hallway3->GetName(), "Hallway 3");
  map.Deallocate();
}
