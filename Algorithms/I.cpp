#include <cstdint>
#include <iostream>

uint64_t SearchSize(const uint64_t &w, const uint64_t &h, const uint64_t &n) {
  uint64_t min_size = 0;
  uint64_t max_size = 0;
  if (h > w) {
    min_size = h;
    max_size = n * h;
  } else {
    min_size = w;
    max_size = n * w;
  }
  while (min_size < max_size) {
    uint64_t mid = (min_size + max_size) / 2;
    if ((mid / w) * (mid / h) < n) {
      min_size = mid + 1;
    } else {
      max_size = mid;
    }
  }
  return min_size;
}

int main() {
  uint64_t w = 0;
  uint64_t h = 0;
  uint64_t n = 0;
  std::cin >> w >> h >> n;
  std::cout << SearchSize(w, h, n);
  return 0;
}
