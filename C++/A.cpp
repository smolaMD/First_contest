#include <iostream>

bool IsHor(char **arr, const int &line_num) {
  return (arr[line_num][0] == '1' && arr[line_num][1] == '1');
}

bool IsVer(char **arr, const int &col_num) {
  return (arr[0][col_num] == '1' && arr[1][col_num] == '1');
}

void CountHor(char **arr, const int &n, const int &m, int *hor_ind, int &h) {
  if (m > 1) {
    for (int i = 0; i < n; ++i) {
      if (IsHor(arr, i)) {
        hor_ind[h] = i;
        ++h;
      }
    }
  }
}

void CountVert(char **arr, const int &n, const int &m, int *vert_ind, int &v) {
  if (n > 1) {
    for (int i = 0; i < m; ++i) {
      if (IsVer(arr, i)) {
        vert_ind[v] = i;
        ++v;
      }
    }
  }
}

int DefineType(int h, int v, int n, int m, int *hor_ind, int *vert_ind) {
  if (h > 0 && v > 0) {
    return 0;
  }
  if (h > 1 && v == 0) {
    if (m >= hor_ind[1] - hor_ind[0]) {
      return 1;
    }
    return 3;
  }
  if (h == 1 && v == 0) {
    return 3;
  }
  if (h == 0 && v > 1) {
    if (n >= vert_ind[1] - vert_ind[0]) {
      return 2;
    }
    return 3;
  }
  if (h == 0 && v == 1) {
    return 3;
  }
  if (h == 0 && v == 0) {
    return 3;
  }
  return 3;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::cin.ignore();
  char **arr = new char *[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = new char[m];
  }
  for (int i = 0; i < n; ++i) {
    char *tmp_line = new char[m];
    std::cin.getline(tmp_line, m + 1);
    for (int j = 0; j < m; ++j) {
      arr[i][j] = tmp_line[j];
    }
    delete[] tmp_line;
  }
  int *hor_ind = new int[n];
  int *vert_ind = new int[m];
  int h = 0;
  int v = 0;
  CountHor(arr, n, m, hor_ind, h);
  CountVert(arr, n, m, vert_ind, v);
  const char types[4][20] = {"Square", "Line", "Vertical line", "?"};
  std::cout << types[DefineType(h, v, n, m, hor_ind, vert_ind)];
  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
  delete[] hor_ind;
  delete[] vert_ind;
  return 0;
}
