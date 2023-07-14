#include "Item.h"
#include "Exceptions.h"
#include "gtest/gtest.h"


TEST(TestItem, TestConstructor) {
  EXPECT_NO_THROW(Item shovel("Shovel", "It digs"));
}
TEST(TestItem, TestgetName) {
  Item key("Key", "Unlocks doors and what not");
  EXPECT_EQ(key.getName(), "Key");
}
TEST(TestItem, TestgetDescription) {
  Item pickaxe("Pickaxe", "Breaks stone");
  EXPECT_EQ(pickaxe.getDescription(), "Breaks stone");
}
TEST(TestItem, TestUseItemKey) {
  Item key("Key", "Unlocks doors and what not");
  EXPECT_EQ("You unlock the door in the warden's office and escape!",
   key.UseItem("Wardens Office"));
}
TEST(TestItem, TestUseItemLockPick) {
  Item lp("Lockpick", "Picks locks");
  EXPECT_EQ("You start to lockpick your cell door...",
  lp.UseItem("Starting Cell"));
}
TEST(TestItem, TestUseItemShovel) {
  Item shovel("Shovel", "Digs");
  EXPECT_EQ("You dig a tunnel in the courtyard and escape!",
  shovel.UseItem("Courtyard"));
}
TEST(TestItem, TestUseItemPickaxe) {
  Item pa("pickaxe", "Breaks stone");
  EXPECT_EQ("You break through a weak wall in your cell and escape!",
  pa.UseItem("Starting Cell"));
}
TEST(TestItem, TestUseItemInvalid) {
  Item linuxComputer("Linuxbox",
  "Its users insist on opening their browsers from the terminal");
  EXPECT_EQ("You can't use this item here.",
  linuxComputer.UseItem("Computerlab"));
}
