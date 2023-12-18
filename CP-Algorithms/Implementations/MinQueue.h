#include <algorithm>
#include <stack>
#include <stdexcept>

template <typename T>
class MinQueue {
 public:
  void push(T elem) {
    if (back.empty())
      back.push({elem, elem});
    else
      back.push({elem, std::min(elem, back.top().second)});
  }
  T pop() {
    if (front.empty()) {
      while (!back.empty()) {
        T elem = back.top().first;
        back.pop();
        if (front.empty()) {
          front.push({elem, elem});
        } else {
          front.push({elem, std::min(elem, front.top().second)});
        }
      }
    }
    if (front.empty()) {
      throw std::runtime_error("Queue is empty");
    }
    T elem = front.top().first;
    front.pop();
    return elem;
  }
  T minimum() {
    if (front.empty() && back.empty()) {
      throw std::runtime_error("Queue is empty");
    }
    if (front.empty()) {
      return back.top().second;
    }
    if (back.empty()) {
      return front.top().second;
    }
    return std::min(front.top().second, back.top().second);
  }

 private:
  std::stack<std::pair<T, T>> front;
  std::stack<std::pair<T, T>> back;
};