#include "bits/stdc++.h"
using namespace std;
class Interesting_Drink {
 public:
  Interesting_Drink() {
    int num_shops;
    int bottle_prices[100'000];
    int num_days;
    int num_coins[100'000];
    cin >> num_shops;
    for (int i = 0; i < num_shops; i++) {
      cin >> bottle_prices[i];
    }
    cin >> num_days;
    for (int i = 0; i < num_days; i++) {
      cin >> num_coins[i];
    }
    std::sort(bottle_prices, bottle_prices + num_shops);

    for (int i = 0; i < num_days; i++) {
      auto pos =
          std::lower_bound(bottle_prices, bottle_prices + num_shops,
                           num_coins[i], [](int a, int b) { return a <= b; });
      int num_beers = std::distance(bottle_prices, pos);

      cout << num_beers << endl;
    }
  }
};
int main() { Interesting_Drink a{}; }