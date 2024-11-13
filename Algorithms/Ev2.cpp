#include <iostream>

void MakeOne(int n, int *&arr, bool make_first = false);

void MakeZero(int n, int *&arr) {
  if (n == 0) {
    if (arr[n] != 0) {
      std::cout << -1 * (n + 1) << ' ';
      arr[n] = 0;
    }
    return;
  }
  if (n == 1) {
    if (arr[n] != 0) {
      MakeOne(n - 1, arr);
      std::cout << -1 * (n + 1) << ' ';
      arr[n] = 0;
    }
    MakeZero(n - 1, arr);
    return;
  }
  if (arr[n] == 0) {
    MakeZero(n - 1, arr);
  } else {
    MakeOne(n - 1, arr, true);
    std::cout << -1 * (n + 1) << ' ';
    arr[n] = 0;
    MakeZero(n - 1, arr);
  }
}

void MakeOne(int n, int *&arr, bool make_first) {
  if (n == 0) {
    if (arr[n] != 1) {
      std::cout << n + 1 << ' ';
      arr[n] = 1;
    }
    return;
  }
  if (n == 1) {
    if (arr[n] != 1) {
      MakeOne(n - 1, arr, true);
      std::cout << n + 1 << ' ';
      arr[n] = 1;
    }
    if (make_first) {
      MakeZero(n - 1, arr);
    }
    return;
  }
  if (arr[n] == 1) {
    if (make_first) {
      MakeZero(n - 1, arr);
    }
    return;
  }
  if (arr[n - 1] == 0) {
    MakeOne(n - 1, arr, true);
    std::cout << n + 1 << ' ';
    arr[n] = 1;
    if (make_first) {
      MakeZero(n - 1, arr);
    }
    return;
  }
  // if (arr[n - 2] == 1)
  MakeZero(n - 2, arr);
  std::cout << n + 1 << ' ';
  arr[n] = 1;
  if (make_first) {
    MakeZero(n - 1, arr);
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int *arr = new int[n]{};
  for (int i = n - 1; i > -1; --i) {
    MakeOne(i, arr, false);
  }
  std::cout << '\n';

  delete[] arr;
  return 0;
}
