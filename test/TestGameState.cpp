#include <vector>
#include <string>
#include <iostream>
#include "GameState.h"
#include "MapGenerator.h"
#include "Exceptions.h"
#include "gtest/gtest.h"


TEST(TestGameState, TestBackToHallway) {
  MapGen map;
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = map.GenerateMap();
  state.currentHallway = nullptr;
  state.currentStoryRoom->isLocked = false;
  state.BackToHallway();
  EXPECT_EQ(state.currentHallway->GetName(), "Hallway 3");
  map.Deallocate();
  delete state.player;
}
TEST(TestGameState, TestMoveRight) {
  MapGen map;
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = map.GenerateMap();
  state.currentHallway = nullptr;
  state.currentStoryRoom->isLocked = false;
  state.BackToHallway();
  state.MoveRight();
  EXPECT_EQ(state.currentStoryRoom->GetName(), "Labour Camp");
  map.Deallocate();
  delete state.player;
}
TEST(TestGameState, TestMoveLeft) {
  MapGen map;
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = map.GenerateMap();
  state.currentHallway = nullptr;
  state.currentStoryRoom->isLocked = false;
  state.BackToHallway();
  state.MoveLeft();
  EXPECT_EQ(state.currentHallway->GetName(), "Hallway 2");
  map.Deallocate();
  delete state.player;
}
TEST(TestGameState, TestMoveUp) {
  MapGen map;
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = map.GenerateMap();
  state.currentHallway = nullptr;
  state.currentStoryRoom->isLocked = false;
  state.BackToHallway();
  state.MoveUp();
  EXPECT_EQ(state.currentStoryRoom->GetName(), "Showers");
  map.Deallocate();
  delete state.player;
}
TEST(TestGameState, TestMoveDown) {
  MapGen map;
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = map.GenerateMap();
  state.currentHallway = nullptr;
  state.currentStoryRoom->isLocked = false;
  state.BackToHallway();
  state.MoveDown();
  EXPECT_EQ(state.currentStoryRoom->GetName(), "Starting Cell");
  map.Deallocate();
  delete state.player;
}
TEST(TestGameState, TestPickUp) {
  MapGen map;
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = map.GenerateMap();
  state.currentHallway = nullptr;
  state.PickUp("Lockpick", 0);
  std::vector<Item>::iterator it;
  std::string testString;
  for (it = state.player->items.begin(); it < state.player->items.end(); ++it) {
    if (it->getName() == "Lockpick") {
      testString = "Lockpick";
    }
  }
  EXPECT_EQ(testString, "Lockpick");
  map.Deallocate();
  delete state.player;
}
TEST(TestGameState, TestDrop) {
  MapGen map;
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = map.GenerateMap();
  state.currentHallway = nullptr;
  state.PickUp("Lockpick", 0);
  state.Drop("Lockpick", 0);
  std::vector<Item>::iterator it;
  std::string testString;
  for (it = state.currentStoryRoom->_items.begin();
  it < state.currentStoryRoom->_items.end(); ++it) {
    if (it->getName() == "Lockpick") {
      testString = "Lockpick";
    }
  }
  EXPECT_EQ(testString, "Lockpick");
  map.Deallocate();
  delete state.player;
}

TEST(TestGameState, TestGetCurrentRoom) {
  MapGen map;
  StoryRoom *r = map.GenerateMap();
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = r;
  state.currentHallway = nullptr;
  state.currentStoryRoom->isLocked = false;
  EXPECT_EQ(state.GetCurrentRoom()->GetName(), "Starting Cell");
  map.Deallocate();
  delete state.player;
}
TEST(TestGameState, TestGetCurrentHallway) {
  MapGen map;
  StoryRoom *r = map.GenerateMap();
  GameState state;
  state.player = new Player();
  state.currentStoryRoom = r;
  state.currentHallway = nullptr;
  state.currentStoryRoom->isLocked = false;
  state.BackToHallway();
  EXPECT_EQ(state.GetCurrentHallway()->GetName(), "Hallway 3");
  map.Deallocate();
  delete state.player;
}
