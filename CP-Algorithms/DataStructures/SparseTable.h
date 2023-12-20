#include <bit>
#include <iostream>
#include <span>
#include <vector>

// I hate this implementation
// it's the worst combo of generic/not-generic
template <typename T, long N, typename F, int K = 25>
class SparseTable {
 public:
  T table[K + 1][N];
  SparseTable(std::span<T> arr, F f) {
    for (long i = 0; i < arr.size(); i++) {
      table[0][i] = arr[i];
    }
    for (int i = 1; i <= K; i++) {
      for (int j = 0; j + (1 << (i - 1)) < N; j++) {
        table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  static constexpr int lg_2_floor(unsigned long a) {
    return std::bit_width(a) - 1;
  }
  T RangeMinimumQuery(unsigned long l, unsigned long r) {
    int power_of_two = lg_2_floor(r - l + 1);
    return std::min(table[power_of_two][l],
                    table[power_of_two][r - (1 << power_of_two) + 1]);
  };
  T RangeSumQuery(long l, long r) {
    T sum = 0;
    for (long i = K; i >= 0; i--) {
      if ((1 << (i)) <= (r - l + 1)) {
        sum += table[i][l];
        l += (1 << (i));
      }
    }
    return sum;
  }
};