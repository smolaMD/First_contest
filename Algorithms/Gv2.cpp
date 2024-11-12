#include <iostream>

void MergeVector(int array[], int left, int mid, int right) {
  int *tmp_arr = new int[right - left];
  int first_pointer = left;
  int second_pointer = mid;
  int cnt = 0;
  while (first_pointer < mid && second_pointer < right) {
    if (array[first_pointer] <= array[second_pointer]) {
      tmp_arr[cnt] = array[first_pointer];
      ++first_pointer;
    } else {
      tmp_arr[cnt] = array[second_pointer];
      ++second_pointer;
    }
    ++cnt;
  }
  while (first_pointer < mid) {
    tmp_arr[cnt] = array[first_pointer];
    ++cnt;
    ++first_pointer;
  }
  while (second_pointer < right) {
    tmp_arr[cnt] = array[second_pointer];
    ++cnt;
    ++second_pointer;
  }
  for (int h = 0; h < right - left; ++h) {
    array[left + h] = tmp_arr[h];
  }
  delete[] tmp_arr;
}

int main() {
  int k = 0;
  std::cin >> k;
  int input_pointer = 0;
  int *length = new int[k + 1];  // prefix_sum
  int *res_array = new int[1000005];
  length[0] = 0;
  for (int i = 0; i < k; ++i) {
    int n = 0;
    std::cin >> n;
    length[i + 1] = length[i] + n;
    for (int j = 0; j < n; ++j) {
      std::cin >> res_array[input_pointer + j];
    }
    input_pointer += n;
  }
  int flag_cnt = 0;
  int flags[100];  // сигнализирует о том, было ли количество массивов четное или нечетное на каждой итерации сливания
  for (int u = 0; u < 100; ++u) {
    flags[u] = -1;
  }
  int cnt = k;
  int manager = 1;
  while (cnt > 1) {
    for (int i = 0; i + 2 <= cnt; i += 2) {
      MergeVector(res_array, length[i * manager], length[(i + 1) * manager], length[(i + 2) * manager]);
    }
    if (cnt % 2 == 0) {
      flags[flag_cnt] = 0;
    } else {
      flags[flag_cnt] = 1;
    }
    ++flag_cnt;
    cnt /= 2;
    manager *= 2;
  }
  for (int i = flag_cnt - 1; i > -1; --i) {
    if (flags[i] == 0) {
      manager /= 2;
      cnt *= 2;
    } else {
      manager /= 2;
      cnt *= 2;
      cnt++;
      MergeVector(res_array, length[0], length[(cnt - 1) * manager], length[cnt * manager]);
    }
  }
  for (int i = 0; i < input_pointer; ++i) {
    std::cout << res_array[i] << " ";
  }
  delete[] length;
  delete[] res_array;
  return 0;
}
