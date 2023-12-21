#include <iostream>
#include <utility>

template <typename F>
class TernarySearch {
 public:
  TernarySearch(F f) : f(f) {}
  auto minimum(double l, double r) -> decltype(std::declval<F>()(0)) {
    double epsilon = std::numeric_limits<double>::epsilon();
    while (r - l > epsilon) {
      double ml = l + (r - l) / 3;
      double mr = r - (r - l) / 3;
      auto ml_val = f(ml);
      auto mr_val = f(mr);
      if (ml_val > mr_val) {
        l = ml;
      } else if (ml_val < mr_val) {
        r = mr;
      } else {
        l = ml;
        r = mr;
      }
    }
    return f(r);
  }
  auto maximum(double l, double r) -> decltype(std::declval<F>()(0)) {
    double epsilon = std::numeric_limits<double>::epsilon();
    while (r - l > epsilon) {
      double ml = l + (r - l) / 3;
      double mr = r - (r - l) / 3;
      auto ml_val = f(ml);
      auto mr_val = f(mr);
      if (ml_val > mr_val) {
        r = mr;
      } else if (ml_val < mr_val) {
        l = ml;
      } else {
        l = ml;
        r = mr;
      }
    }
    return f(r);
  }

 private:
  F f;
};