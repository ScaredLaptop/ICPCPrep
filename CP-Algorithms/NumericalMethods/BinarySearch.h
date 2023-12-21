template <typename T>
class BinarySearch {
 public:
  BinarySearch(std::span<T> arr) : arr(arr){};
  std::optional<int> search(T val) {
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (arr[mid] == val) {
        return mid;
      } else if (arr[mid] < val) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return std::nullopt;
  }

 private:
  std::span<T> arr;
};