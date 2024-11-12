#include <iostream>

void Sort(int *begin, int *end) {
  if (end - begin < 2) {
    return;
  }
  int *i = begin;
  int *j = end - 1;
  int pivot = *(begin + (end - begin) / 2);
  while (i - 1 < j) {
    while (*i < pivot) {
      ++i;
    }
    while (pivot < *j) {
      --j;
    }
    if (i <= j) {
      int tmp = *i;
      *i = *j;
      *j = tmp;
      ++i;
      --j;
    }
  }
  Sort(begin, j + 1);
  Sort(i, end);
}

int UpperBound(const int *begin, const int *end, const int &value) {
  int i = -1;
  int j = static_cast<int>(end - begin);
  while (i < j - 1) {
    int mid = (i + j) / 2;
    if (value < *(begin + mid)) {
      j = mid;
    } else {
      i = mid;
    }
  }
  return j;
}

bool Check(const int &d, const int *senat, const int &n, const int &m, const int &k) {
  int cnt = 0;
  for (int i = 0; i < n;) {
    int pos = UpperBound(senat, senat + n, senat[i] + d);
    if (pos - i >= k) {
      ++cnt;
      i += k;
    } else {
      ++i;
    }
  }
  return cnt >= m;
}

int BinarySearch(const int *senat, const int &n, const int &m, const int &k) {
  int left = -1;
  int right = senat[n - 1];
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (Check(mid, senat, n, m, k)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}

int main() {
  int n = 0;
  int m = 0;
  int k = 0;
  std::cin >> n >> m >> k;
  int *senat = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> senat[i];
  }
  Sort(senat, senat + n);
  std::cout << BinarySearch(senat, n, m, k);
  delete[] senat;
  return 0;
}
