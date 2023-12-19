#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

#include "MinQueue.h"
#include "MinStack.h"
#include "SparseTable.h"

TEST(SparseTableTest, BasicTests) {
  std::vector<long> data;
  for (int i = 0; i < 100; i++) {
    data.push_back(i);
  }

  auto minFunc = [](long a, long b) -> long { return std::min(a, b); };
  std::span<long> data_span = data;
  SparseTable<long, 100, decltype(minFunc)> sparseTable(data_span, minFunc);
  EXPECT_EQ(sparseTable.RangeMinimumQuery(0, 2), 0);
  EXPECT_EQ(sparseTable.RangeMinimumQuery(5, 10), 5);
  EXPECT_EQ(sparseTable.RangeMinimumQuery(20, 55), 20);
  EXPECT_EQ(sparseTable.RangeMinimumQuery(58, 59), 58);
  auto sum = [](long a, long b) -> long { return a + b; };
  SparseTable<long, 100, decltype(sum)> sparseTable2(data_span, sum);
  EXPECT_EQ(sparseTable2.RangeSumQuery(0, 2), 3);
  EXPECT_EQ(sparseTable2.RangeSumQuery(1, 2), 3);
  EXPECT_EQ(sparseTable2.RangeSumQuery(5, 10), 45);
  EXPECT_EQ(sparseTable2.RangeSumQuery(20, 55), 1350);
}

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