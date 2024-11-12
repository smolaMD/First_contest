#include <iostream>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  int i = 0;
  int j = k - 1;
  while (j <= n - 1) {
    int min_num = arr[i];
    for (int k = i; k <= j; ++k) {
      if (arr[k] < min_num) {
        min_num = arr[k];
      }
    }
    std::cout << min_num << '\n';
    ++i;
    ++j;
  }
  delete[] arr;
  return 0;
}
