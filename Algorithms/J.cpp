#include <cstring>
#include <iostream>

struct Student {
  char surname[41];
  char name[41];
  int inf = 0;
  int mat = 0;
  int rus = 0;
};

double Score(Student student) {
  return (student.inf + student.mat + student.rus) / 3.0;
}

void Merge(Student *arr, int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  auto *temp_arr = new Student[right - left + 1];
  int temp_ind = 0;
  while (i <= mid && j <= right) {
    if (Score(arr[i]) < Score(arr[j])) {
      temp_arr[temp_ind] = arr[i];
      ++temp_ind;
      ++i;
    } else {
      temp_arr[temp_ind] = arr[j];
      ++temp_ind;
      ++j;
    }
  }
  while (i <= mid) {
    temp_arr[temp_ind] = arr[i];
    ++temp_ind;
    ++i;
  }
  while (j <= right) {
    temp_arr[temp_ind] = arr[j];
    ++temp_ind;
    ++j;
  }
  for (int i = 0; i < right - left + 1; ++i) {
    arr[left + i] = temp_arr[i];
  }
  delete[] temp_arr;
}

void MergeSort(Student *arr, int left, int right) {
  if (right - left <= 0) {
    return;
  }
  int mid = (left + right) / 2;
  MergeSort(arr, left, mid);
  MergeSort(arr, mid + 1, right);
  Merge(arr, left, mid, right);
}

int main() {
  int n = 0;
  std::cin >> n;
  auto *arr = new Student[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i].surname >> arr[i].name >> arr[i].inf >> arr[i].mat >> arr[i].rus;
  }
  int left = 0;
  MergeSort(arr, left, n - 1);
  for (int i = n - 1; i >= 0; --i) {
    std::cout << arr[i].surname << " " << arr[i].name << '\n';
  }
  delete[] arr;
  return 0;
}
