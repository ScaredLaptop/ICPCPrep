#include <gtest/gtest.h>
#include "MinStack.h"

// Demonstrate some basic assertions.
TEST(MinStackTest, BasicTests) {
  MinStack<int> a;
  a.push(1);
  EXPECT_EQ(a.top(), 1);
  EXPECT_EQ(a.min(), 1);
}