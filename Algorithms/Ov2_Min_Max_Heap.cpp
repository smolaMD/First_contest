#include <iostream>
#include <cstring>

struct MMHeap {
  int size = 0;
  int capacity = 200005;
  int *arr = new int[capacity];

  void PushDown(int index) {
    while (HasChildren(index)) {
      int tmp = index;
      if (IsMinLevel(tmp)) {
        index = FoundMinChild(tmp);
        if (arr[tmp] > arr[index]) {
          std::swap(arr[index], arr[tmp]);
          if (IsGrandChild(index, tmp)) {
            int index_of_parent = GetParent(index);
            if (arr[index] > arr[index_of_parent]) {
              std::swap(arr[index], arr[index_of_parent]);
            }
          } else {
            break;
          }
        } else {
          break;
        }
      } else {
        index = FoundMaxChild(tmp);
        if (arr[index] > arr[tmp]) {
          std::swap(arr[index], arr[tmp]);
          if (IsGrandChild(index, tmp)) {
            int index_of_parent = GetParent(index);
            if (arr[index] < arr[index_of_parent]) {
              std::swap(arr[index], arr[index_of_parent]);
            }
          } else {
            break;
          }
        } else {
          break;
        }
      }
    }
  }

  void AddElement(int value) {
    arr[size] = value;
    size++;
    PushUp(size - 1);
  }

  void PushUp(int index) {
    if (index != 0) {
      if (IsMinLevel(index)) {
        int index_of_parent = GetParent(index);
        if (arr[index] > arr[index_of_parent]) {
          std::swap(arr[index], arr[index_of_parent]);
          PushUpMax(index_of_parent);
        } else {
          PushUpMin(index);
        }
      } else {
        int index_of_parent = GetParent(index);
        if (arr[index] < arr[index_of_parent]) {
          std::swap(arr[index], arr[index_of_parent]);
          PushUpMin(index_of_parent);
        } else {
          PushUpMax(index);
        }
      }
    }
  }

  int FindMin() {
    if (size == 0) {
      return -1;
    }
    return 0;
  }

  int FindMax() {
    if (size == 0) {
      return -1;
    }
    if (size == 1) {
      return 0;
    }
    if (size == 2) {
      return 1;
    }
    if (size > 2) {
      if (arr[1] > arr[2]) {
        return 1;
      }
      return 2;
    }
    return -1;
  }

  void RemoveMin() {
    int index = 0;
    if (size == 0) {
      return;
    }
    int temp = size - 1;
    arr[index] = arr[temp];
    --size;
    PushDown(index);
  }

  void RemoveMax() {
    if (size == 0) {
      return;
    }
    int index = FindMax();
    int temp = size - 1;
    arr[index] = arr[temp];
    --size;
    PushDown(index);
  }

  void Clear() {
    size = 0;
  }

  void Exit() {
    delete[] arr;
    size = 0;
  }

 private:
  int GetGrandParent(int index) {
    return ((index - 1) / 2 - 1) / 2;
  }

  int GetParent(int index) {
    return (index - 1) / 2;
  }

  bool IsGrandChild(int index, int parent) {
    if (index <= 2) {
      return false;
    }
    return ((index - 1) / 2 - 1) / 2 == parent;
  }

  bool HasChildren(int index) {
    return index * 2 + 1 < size;
  }

  bool IsMinLevel(int index) {
    int cnt = 0;
    index += 1;
    while (index > 0) {
      index = index / 2;
      ++cnt;
    }
    return cnt % 2;
  }

  int FoundMinChild(int index) {
    int index_of_min_child = index * 2 + 1;
    if (index_of_min_child + 1 < size) {
      if (arr[index_of_min_child + 1] < arr[index_of_min_child]) {
        index_of_min_child = index_of_min_child + 1;
      }
      if ((index * 2 + 1) * 2 + 1 < size) {
        if (arr[(index * 2 + 1) * 2 + 1] < arr[index_of_min_child]) {
          index_of_min_child = (index * 2 + 1) * 2 + 1;
        }
        if ((index * 2 + 1) * 2 + 2 < size) {
          if (arr[(index * 2 + 1) * 2 + 2] < arr[index_of_min_child]) {
            index_of_min_child = (index * 2 + 1) * 2 + 2;
          }
          if ((index * 2 + 2) * 2 + 1 < size) {
            if (arr[(index * 2 + 2) * 2 + 1] < arr[index_of_min_child]) {
              index_of_min_child = (index * 2 + 2) * 2 + 1;
            }
            if ((index * 2 + 2) * 2 + 2 < size) {
              if (arr[(index * 2 + 2) * 2 + 2] < arr[index_of_min_child]) {
                index_of_min_child = (index * 2 + 2) * 2 + 2;
              }
            }
          }
        }
      }
    }
    return index_of_min_child;
  }

  int FoundMaxChild(int index) {
    int index_of_max_child = index * 2 + 1;
    if (index_of_max_child + 1 < size) {
      if (arr[index_of_max_child + 1] > arr[index_of_max_child]) {
        index_of_max_child = index_of_max_child + 1;
      }
      if ((index * 2 + 1) * 2 + 1 < size) {
        if (arr[(index * 2 + 1) * 2 + 1] > arr[index_of_max_child]) {
          index_of_max_child = (index * 2 + 1) * 2 + 1;
        }
        if ((index * 2 + 1) * 2 + 2 < size) {
          if (arr[(index * 2 + 1) * 2 + 2] > arr[index_of_max_child]) {
            index_of_max_child = (index * 2 + 1) * 2 + 2;
          }
          if ((index * 2 + 2) * 2 + 1 < size) {
            if (arr[(index * 2 + 2) * 2 + 1] > arr[index_of_max_child]) {
              index_of_max_child = (index * 2 + 2) * 2 + 1;
            }
            if ((index * 2 + 2) * 2 + 2 < size) {
              if (arr[(index * 2 + 2) * 2 + 2] > arr[index_of_max_child]) {
                index_of_max_child = (index * 2 + 2) * 2 + 2;
              }
            }
          }
        }
      }
    }
    return index_of_max_child;
  }

  void PushUpMin(int index) {
    while (index > 2 && arr[index] < arr[GetGrandParent(index)]) {
      std::swap(arr[index], arr[GetGrandParent(index)]);
      index = GetGrandParent(index);
    }
    // return index;
  }

  void PushUpMax(int index) {
    while (index > 2 && arr[index] > arr[GetGrandParent(index)]) {
      std::swap(arr[index], arr[GetGrandParent(index)]);
      index = GetGrandParent(index);
    }
    // return index;
  }
};

int main() {
  MMHeap heap;
  char input[100];
  int n = 0;
  int value = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> input;
    if (strcmp("insert", input) == 0) {
      std::cin >> value;
      heap.AddElement(value);
      std::cout << "ok\n";
    }
    if (strcmp("extract_min", input) == 0) {
      value = heap.FindMin();
      if (value == -1) {
        std::cout << "error\n";
      } else {
        std::cout << heap.arr[value] << '\n';
        heap.RemoveMin();
      }
    }
    if (strcmp("extract_max", input) == 0) {
      value = heap.FindMax();
      if (value == -1) {
        std::cout << "error\n";
      } else {
        std::cout << heap.arr[value] << '\n';
        heap.RemoveMax();
      }
    }
    if (strcmp("get_min", input) == 0) {
      value = heap.FindMin();
      if (value == -1) {
        std::cout << "error\n";
      } else {
        std::cout << heap.arr[value] << '\n';
      }
    }
    if (strcmp("get_max", input) == 0) {
      value = heap.FindMax();
      if (value == -1) {
        std::cout << "error\n";
      } else {
        std::cout << heap.arr[value] << '\n';
      }
    }
    if (strcmp("size", input) == 0) {
      std::cout << heap.size << "\n";
    }
    if (strcmp("clear", input) == 0) {
      heap.Clear();
      std::cout << "ok\n";
    }
  }
  heap.Exit();
}
