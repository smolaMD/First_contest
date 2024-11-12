#include <iostream>

void PrintStep(int n, int num_1, int num_2) {
  std::cout << n << " " << num_1 << " " << num_2 << '\n';
}

void Moving(int n, int num_1, int num_2) {
  if (n == 0) {
    return;
  }
  int tmp_num = 6 - num_1 - num_2;
  Moving(n - 1, num_1, tmp_num);
  PrintStep(n, num_1, num_2);
  Moving(n - 1, tmp_num, num_2);
}

int main() {
  int n = 0;
  std::cin >> n;
  int num_1 = 1;
  int num_2 = 3;
  Moving(n, num_1, num_2);
  return 0;
}
