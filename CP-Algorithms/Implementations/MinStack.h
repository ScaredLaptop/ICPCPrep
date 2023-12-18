#include <stdexcept>
#include <stack>
#include <utility>
#include <concepts>

template <typename T>
requires requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
}
class MinStack {
public:
    void push(T elem) {
        if(s.empty() || elem < min()) {
            s.push({elem, elem});
        } else {
            s.push({elem, min()});
        }
    }

    T pop() {
        if(s.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        T elem = s.top().first;
        s.pop();
        return elem;
    }
    T top(){
        if(s.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return s.top().first;
    }
    T min() {
        if(s.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return s.top().second;
    }

private:
    std::stack<std::pair<T, T>> s;
};
