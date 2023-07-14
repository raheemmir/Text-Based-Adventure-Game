#include "GameState.h"
#include "MapGenerator.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestRoom, TestHallwayConstructor) {
  EXPECT_NO_THROW(Hallway1());
}
TEST(TestRoom, TestHallwayConstructor2) {
  EXPECT_NO_THROW(Hallway2());
}
TEST(TestRoom, TestHallwayConstructor3) {
  EXPECT_NO_THROW(Hallway3());
}
TEST(TestRoom, TestStoryRoomConstructor1) {
  EXPECT_NO_THROW(Courtyard());
}
TEST(TestRoom, TestStoryRoomConstructor2) {
  EXPECT_NO_THROW(Cafeteria());
}
TEST(TestRoom, TestStoryRoomConstructor3) {
  EXPECT_NO_THROW(StartingCell());
}
TEST(TestRoom, TestStoryRoomConstructor4) {
  EXPECT_NO_THROW(Gallows());
}
TEST(TestRoom, TestStoryRoomConstructor5) {
  EXPECT_NO_THROW(WardensOffice());
}
TEST(TestRoom, TestStoryRoomConstructor6) {
  EXPECT_NO_THROW(Showers());
}
TEST(TestRoom, TestStoryRoomConstructor7) {
  EXPECT_NO_THROW(LabourCamp());
}
TEST(TestRoom, TestStoryRoomConstructor8) {
  EXPECT_NO_THROW(Cell());
}
TEST(TestRoom, TestRoomFunc1) {
  StoryRoom r;
  r = StartingCell();
  EXPECT_EQ(r.GetName(), "Starting Cell");
}
TEST(TestRoom, TestRoomFunc2) {
  StoryRoom r;
  r = StartingCell();
  EXPECT_EQ(r.GetDescription(), "This is the cell you wake up in.");
}
TEST(TestRoom, TestRoomFunc3) {
  StoryRoom r;
  r = StartingCell();
  EXPECT_EQ(r.GetDescription(), "This is the cell you wake up in.");
}
TEST(TestRoom, TestRoomFunc4) {
  StoryRoom r;
  r = StartingCell();
  EXPECT_FALSE(r.isHallway());
}
TEST(TestRoom, TestStoryRoomGetInv) {
  StoryRoom r;
  r = StartingCell();
  Item linuxComputer("Linuxbox", "screenshotting is difficult");
  r._items.push_back(linuxComputer);
  EXPECT_TRUE(r.GetInventory());
}
TEST(TestRoom, TestIsHallway) {
  Hallway* h = new Hallway1();
  EXPECT_TRUE(h->isHallway());
  delete h;
}



 /*
class TestRoom : public ::testing::Test {
 public:
  GameState gs;
  MapGen mg;

  TestRoom() : gs(GameState()) {}

  void SetUp() {
     // Set up the test environment
    gs.currentHallway = nullptr;
    gs.currentStoryRoom = nullptr;
    gs.currentStoryRoom = mg.GenerateMap();
    gs.player = new Player();
  }

  void TearDown() {
    // Clean up the test environment
    if (gs.currentHallway != nullptr) {
      delete gs.currentHallway;
      gs.currentHallway = nullptr;
    }
    if (gs.currentStoryRoom != nullptr) {
      delete gs.currentStoryRoom;
      gs.currentStoryRoom = nullptr;
    }
    if (gs.player != nullptr) {
      delete gs.player;
      gs.player = nullptr;
    }
    mg.Deallocate();
  }
};

TEST_F(TestRoom, TestGetName) {
  Room room;
  room._name = "Test Room";
  EXPECT_EQ(room.GetName(), "Test Room");
}

TEST_F(TestRoom, TestGetDescription) {
  Room room;
  room._description = "This is a test room description.";
  EXPECT_EQ(room.GetDescription(), "This is a test room description.");
}

TEST_F(TestRoom, TestCheckHallway) {
  StoryRoom room;
  EXPECT_FALSE(room.isHallway());
  Hallway hallway = Hallway("Hallway 1", "This is the first hallway");
  EXPECT_TRUE(hallway.isHallway());
}

TEST_F(TestRoom, TestBackToHallway) {
  SetUp();
  gs.BackToHallway();
  EXPECT_EQ("Hallway 3", gs.currentHallway->_name);
  TearDown();
}

TEST_F(TestRoom, TestMoveRight) {
  SetUp();
  gs.BackToHallway();
  gs.MoveRight();
  EXPECT_EQ("Labour Camp", gs.currentStoryRoom->_name);
  TearDown();
}

TEST_F(TestRoom, TestMoveLeft) {
  SetUp();
  gs.BackToHallway();
  gs.MoveLeft();
  EXPECT_EQ("Hallway 2", gs.currentHallway->_name);
  TearDown();
}

TEST_F(TestRoom, TestMoveUp) {
  SetUp();
  gs.BackToHallway();
  gs.MoveUp();
  EXPECT_EQ("Showers", gs.currentStoryRoom->_name);
  TearDown();
}

TEST_F(TestRoom, TestMoveDown) {
  SetUp();
  gs.BackToHallway();
  gs.MoveDown();
  EXPECT_EQ("Starting Cell", gs.currentStoryRoom->_name);
  TearDown();
}
*/
