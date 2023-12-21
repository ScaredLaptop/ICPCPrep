#include "bits/stdc++.h"
using namespace std;
class Weakness_And_Poorness {
 public:
  Weakness_And_Poorness() {
    // Find largest pos and largest neg segment O(n)
    // start x = 0; [-5000, 5000]
    int seq_len;
    int a_arr[200'000];
    cin >> seq_len;
    cout << std::setprecision(12);
    for (int i = 0; i < seq_len; i++) {
      cin >> a_arr[i];
    }
    auto weakness = [seq_len, &a_arr](double x) {
      // pos max
      double running_max = 0;
      double biggest_max = std::numeric_limits<double>::min();
      for (int i = 0; i < seq_len; i++) {
        running_max += a_arr[i] - x;
        biggest_max = std::max(running_max, biggest_max);
        if (running_max < 0) {
          running_max = 0;
        }
      }
      // cout << "\nBiggest max+ for " << x << " is " << biggest_max;
      //   neg max
      double running_min = 0;
      double biggest_min = std::numeric_limits<double>::max();
      for (int i = 0; i < seq_len; i++) {
        running_min += a_arr[i] - x;
        biggest_min = std::min(running_min, biggest_min);
        if (running_min > 0) {
          running_min = 0;
        }
      }
      // cout << "\nBiggest max- for " << x << " is " << -biggest_min;
      return std::max(-biggest_min, biggest_max);
    };
    double r = std::max(
        abs(static_cast<double>(*std::max_element(a_arr, a_arr + seq_len))),
        abs(static_cast<double>(*std::min_element(a_arr, a_arr + seq_len))));
    double l = -r;
    double eps = 1e-13;
    while ((r - l) > eps) {
      double ml = l + (r - l) / 3;
      double mr = r - (r - l) / 3;
      double w_ml = weakness(ml);

      double w_mr = weakness(mr);
      if (w_ml > w_mr) {
        l = ml;
      } else if (w_ml < w_mr) {
        r = mr;
      } else {
        l = ml;
        r = mr;
      }
    }
    cout << weakness(l);
  }
};

int main() { Weakness_And_Poorness wap{}; }