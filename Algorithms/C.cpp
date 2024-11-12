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

void Uniq(const int *arr, int *uniq_arr, const int &n, int &size) {
  for (int i = 1; i < n; ++i) {
    if (arr[i] != arr[i - 1]) {
      uniq_arr[size] = arr[i];
      ++size;
    }
  }
  ++size;
}

bool Comparation(const int *arr1, const int *arr2, const int &size1, const int &size2) {
  if (size1 != size2) {
    return false;
  }
  for (int i = 0; i < size1; ++i) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 0;
  std::cin >> n;
  int *skywoker = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> skywoker[i];
  }
  int m = 0;
  std::cin >> m;
  int *planet = new int[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> planet[i];
  }
  Sort(skywoker, skywoker + n);
  Sort(planet, planet + m);
  int *uniq_sk = new int[n];
  int sk_size = 0;
  int *uniq_pl = new int[m];
  int pl_size = 0;
  Uniq(skywoker, uniq_sk, n, sk_size);
  Uniq(planet, uniq_pl, m, pl_size);
  if (Comparation(uniq_sk, uniq_pl, sk_size, pl_size)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  delete[] skywoker;
  delete[] planet;
  delete[] uniq_sk;
  delete[] uniq_pl;
  return 0;
}
