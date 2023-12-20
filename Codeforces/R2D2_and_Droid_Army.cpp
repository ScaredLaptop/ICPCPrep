#include "bits/stdc++.h"
using namespace std;
class R2D2_and_Droid_Army {
 public:
  R2D2_and_Droid_Army() {
    int num_droids, num_detail_types, num_available_shots;
    cin >> num_droids >> num_detail_types >> num_available_shots;
    // find longest (l, r) s.t.
    // max(a1) + ... + max(am) <= k

    int input[100001][5];
    for (int i = 0; i < num_droids; i++) {
      for (int j = 0; j < num_detail_types; j++) {
        cin >> input[i][j];
      }
    }

    // (l, r)
    // j, j+2^i -1
    constexpr int k = 25;
    int data[k][100001][5];
    memcpy(data, input, sizeof(int) * 100001 * 5);
    for (int i = 1; i < k; i++) {
      for (int j = 0; j + (1 << (i - 1)) < num_droids; j++) {
        //(j, j + 2^i -1) = (j, j + 2^(i-1) -1) + (j + 2^(i-1), j + 2^(i) -1)
        for (int k = 0; k < num_detail_types; k++) {
          data[i][j][k] =
              std::max(data[i - 1][j][k], data[i - 1][j + (1 << (i - 1))][k]);
        }
      }
    }
    static constexpr auto lg_2_floor = [](unsigned int a) {
      return std::bit_width(a) - 1;
    };
    int bottom = 0;
    int top = num_droids - 1;
    int current = (top - bottom + 1) / 2 + bottom;
    bool valid = false;
    int results[5];
    while (bottom <= top) {
      int power_of_two = lg_2_floor(current + 1);
      for (int i = 0; i + current < num_droids; i++) {
        // (i , j) = (i, i + 2^(power_of_two) - 1) + (j - 2^(power_of_two) + 1,
        // j)
        int required_shots = 0;
        for (int j = 0; j < num_detail_types; j++) {
          required_shots += std::max(
              data[power_of_two][i][j],
              data[power_of_two][i + current - (1 << power_of_two) + 1][j]);
        }
        if (required_shots <= num_available_shots) {
          valid = true;
          for (int j = 0; j < num_detail_types; j++) {
            results[j] = std::max(
                data[power_of_two][i][j],
                data[power_of_two][i + current - (1 << power_of_two) + 1][j]);
          }
          break;
        }
      }
      if (valid) {
        bottom = current + 1;
        valid = false;
      } else {
        top = current - 1;
      }
      /*cout << "Old current:" << current
           << " New current:" << (top - bottom + 1) / 2 + bottom
           << "top:" << top << " bottom:" << bottom << " valid:" << valid
           << endl;*/
      current = (top - bottom + 1) / 2 + bottom;
    }
    for (int i = 0; i < num_detail_types; i++) {
      std::cout << results[i] << " ";
    }
  }
};
int main() {
  R2D2_and_Droid_Army a{};
  exit(0);
}