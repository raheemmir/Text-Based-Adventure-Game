#include <vector>
#include <sstream>
#include "Player.h"
#include "Exceptions.h"
#include "gtest/gtest.h"


TEST(TestPlayer, TestGetName) {
  Player p;
  EXPECT_EQ(p.getName(), "2720Student");
}
TEST(TestPlayer, TestGetItems) {
  Player p;
  Item linuxComputer("Linuxbox", "screenshotting is difficult");
  p.items.push_back(linuxComputer);

  std::stringstream outputBuffer;
  std::streambuf* originalCoutBufffer = std::cout.rdbuf(outputBuffer.rdbuf());

  p.getItems();

  std::cout.rdbuf(originalCoutBufffer);

  std::string expectString = "Here is your item(s):\nLinuxbox\n";
  EXPECT_EQ(outputBuffer.str(), expectString);
}
