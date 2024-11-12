#include <iostream>

void PrintNum(const int &n) {
  std::cout << n << " ";
}

void Push(int n);

void Pop(int n) {
  if (n == 0) {
    return;
  }
  Push(n - 1);
  PrintNum(-n);
  Pop(n - 1);
}

void Push(int n) {
  if (n == 0) {
    return;
  }
  Push(n - 1);
  PrintNum(n);
  Pop(n - 1);
}

void MakeLine(int n) {
  if (n <= 0) {
    return;
  }
  Push(n - 1);
  PrintNum(n);
  MakeLine(n - 2);
}

int main() {
  int n = 0;
  std::cin >> n;
  MakeLine(n);
  return 0;
}
