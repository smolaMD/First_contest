#include <iostream>

void CopyArray(int **arr1, int **arr2, const int &n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      arr1[i][j] = arr2[i][j];
    }
  }
}

void CreateArr(int **arr, const int &x, const int &y) {
  for (int i = 0; i < x; ++i) {
    arr[i] = new int[y];
  }
}

void ClearArr(int **arr, const int &x) {
  for (int i = 0; i < x; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
}

int CountEwoks(int **endor, const int &n, const int &i, const int &j) {
  const int variants[8][2]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  int cnt = 0;
  for (const auto &var : variants) {
    int newi = i + var[0];
    int newj = j + var[1];

    if (newi >= 0 && newi < n && newj >= 0 && newj < n) {
      cnt += endor[newi][newj];
    }
  }

  return cnt;
}

void MovedEwoks(int **endor, int **prev_endor, const int &n) {
  int **emigrants = new int *[n * n];
  CreateArr(emigrants, n * n, 2);
  int **immigrants = new int *[n * n];
  CreateArr(immigrants, n * n, 2);
  int em_size = 0;
  for (int j = 0; j < n; ++j) {
    for (int k = 0; k < n; ++k) {
      int cnt = CountEwoks(endor, n, j, k);
      if (endor[j][k] == 1 && (cnt < 2 || cnt > 3)) {
        emigrants[em_size][0] = j;
        emigrants[em_size][1] = k;
        ++em_size;
      }
    }
  }
  int im_size = 0;
  for (int j = 0; j < n; ++j) {
    for (int k = 0; k < n; ++k) {
      if (endor[j][k] == 0 && (CountEwoks(prev_endor, n, j, k) == 3)) {
        immigrants[im_size][0] = j;
        immigrants[im_size][1] = k;
        ++im_size;
      }
    }
  }
  for (int i = 0; i < im_size; ++i) {
    endor[immigrants[i][0]][immigrants[i][1]] = 1;
  }
  for (int i = 0; i < em_size; ++i) {
    endor[emigrants[i][0]][emigrants[i][1]] = 0;
  }
  ClearArr(emigrants, n * n);
  ClearArr(immigrants, n * n);
}

int main() {
  int n = 0;
  int time = 0;
  std::cin >> n >> time;
  int **endor = new int *[n];
  CreateArr(endor, n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> endor[i][j];
    }
  }
  int **prev_endor = new int *[n];
  CreateArr(prev_endor, n, n);
  CopyArray(prev_endor, endor, n);
  for (int i = 0; i < time; ++i) {
    int **tmp_endor = new int *[n];
    CreateArr(tmp_endor, n, n);
    CopyArray(tmp_endor, endor, n);
    MovedEwoks(endor, prev_endor, n);
    CopyArray(prev_endor, tmp_endor, n);
    ClearArr(tmp_endor, n);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << endor[i][j] << " ";
    }
    std::cout << '\n';
  }
  ClearArr(prev_endor, n);
  ClearArr(endor, n);
  return 0;
}
