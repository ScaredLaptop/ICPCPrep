#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

#include "DataStructures/MinQueue.h"
#include "DataStructures/MinStack.h"
#include "DataStructures/SparseTable.h"
#include "NumericalMethods/BinarySearch.h"
#include "NumericalMethods/NewtonMethod.h"
#include "NumericalMethods/SimpsonFormula.h"
#include "NumericalMethods/TernarySearch.h"

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

TEST(BinarySearch, BasicTests) {
  std::vector<int> a;
  for (int i = 0; i < 100; i++) {
    a.push_back(i);
  }
  BinarySearch bs{std::span<int>{a}};
  EXPECT_EQ(bs.search(1), 1);
  EXPECT_EQ(bs.search(5), 5);
  EXPECT_EQ(bs.search(-2), std::nullopt);
}

TEST(TernarySearch, BasicTests) {
  TernarySearch ts{[](double a) { return a; }};
  EXPECT_NEAR(ts.maximum(0.0, 1.0), 1.0, 1e-11);
  EXPECT_NEAR(ts.minimum(0.0, 1.0), 0.0, 1e-11);
  TernarySearch ts_s{[](double a) {
    if (1 <= a && a <= 2.1) {
      return 2 - a;
    }
    return a;
  }};
  EXPECT_NEAR(ts_s.maximum(0.0, 2.0), 1.0, 1e-11);
}