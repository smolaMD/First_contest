#include <iostream>

void PrintStep(int n, int num_1, int num_2) {
  std::cout << n << " " << num_1 << " " << num_2 << "\n";
}

void Moving(int n, int num_1, int num_2) {
  int tmp_num = 6 - num_1 - num_2;
  if (n == 1) {
    PrintStep(n, num_1, num_2);
  } else {
    Moving(n - 1, num_1, num_2);
    PrintStep(n, num_1, tmp_num);
    Moving(n - 1, num_2, num_1);
    PrintStep(n, tmp_num, num_2);
    Moving(n - 1, num_1, num_2);
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  Moving(n, 1, 3);
  return 0;
}
