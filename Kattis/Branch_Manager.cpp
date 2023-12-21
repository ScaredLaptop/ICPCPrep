#include "bits/stdc++.h"
using namespace std;
class Branch_Manager {
 public:
  struct Node {
    int val;
    int parent;
  };
  Branch_Manager() {
    int cat;
    cin >> cat;
    cin.ignore(1, '\n');
    std::unordered_map<int, Node*> nodes;
    std::string temp;
    while (getline(cin, temp)) {
      if (temp == "-1") {
        break;
      }
      std::vector<int> nums;
      std::size_t start = 0, end = 0;
      while ((end = temp.find(' ', start)) != std::string::npos) {
        nums.push_back(std::stoi(temp.substr(start, end - start)));
        start = end + 1;
      }
      nums.push_back(std::stoi(temp.substr(start)));
      for (int i = 0; i < nums.size(); i++) {
        if (nodes.find(nums[i]) == nodes.end()) {
          nodes[nums[i]] = new Node{.val = nums[i], .parent = -1};
        }
      }
      for (int i = 1; i < nums.size(); i++) {
        nodes[nums[i]] = new Node{.val = nums[i], .parent = nums[0]};
      }
    }
    int cat_node = cat;
    while (cat_node != -1) {
      cout << cat_node << " ";
      cat_node = nodes[cat_node]->parent;
    }
  }
};
int main() { Branch_Manager bm{}; }