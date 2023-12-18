#include <gtest/gtest.h>

#include "MinQueue.h"
#include "MinStack.h"
TEST(MinStackTest, BasicTests) {
  MinStack<int> a;
  a.push(1);
  EXPECT_EQ(a.top(), 1);
  EXPECT_EQ(a.min(), 1);
  EXPECT_EQ(a.pop(), 1);
  EXPECT_THROW(a.pop(), std::runtime_error);
  EXPECT_THROW(a.top(), std::runtime_error);
  EXPECT_THROW(a.min(), std::runtime_error);
  a.push(1);
  a.push(2);
  a.push(0);
  EXPECT_EQ(a.top(), 0);
  EXPECT_EQ(a.min(), 0);
  EXPECT_EQ(a.pop(), 0);
  EXPECT_EQ(a.top(), 2);
  EXPECT_EQ(a.min(), 1);
}
TEST(MinQueueTest, BasicTests) {
  MinQueue<int> a;
  a.push(1);
  EXPECT_EQ(a.minimum(), 1);
  EXPECT_EQ(a.pop(), 1);
  EXPECT_THROW(a.pop(), std::runtime_error);
  EXPECT_THROW(a.minimum(), std::runtime_error);
  a.push(1);
  a.push(2);
  a.push(0);
  EXPECT_EQ(a.minimum(), 0);
  EXPECT_EQ(a.pop(), 1);
  EXPECT_EQ(a.minimum(), 0);
  EXPECT_EQ(a.pop(), 2);
  EXPECT_EQ(a.minimum(), 0);
  EXPECT_EQ(a.pop(), 0);
  EXPECT_THROW(a.pop(), std::runtime_error);
  EXPECT_THROW(a.minimum(), std::runtime_error);
}