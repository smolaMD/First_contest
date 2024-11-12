#include <iostream>

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

struct Element {
  int value = 0;
  int own_index = 0;
  int arr_index = 0;
};

struct Pqueue {
  Element *heap = nullptr;
  int size = 0;

  void SiftDown(int i);
  void SiftUp(int i);
};

void Merge(int **arrs, Pqueue &pqueue, int j, int *sizes, int *res_arr) {
  while (pqueue.size != 0) {
    Element element = pqueue.heap[0];
    pqueue.heap[0] = pqueue.heap[pqueue.size - 1];
    --pqueue.size;
    if (pqueue.size > 0) {
      pqueue.SiftDown(0);
    }
    res_arr[j] = element.value;
    ++j;
    if (element.own_index + 1 < sizes[element.arr_index]) {
      Element new_element;
      new_element.value = arrs[element.arr_index][element.own_index + 1];
      new_element.arr_index = element.arr_index;
      new_element.own_index = element.own_index + 1;
      ++pqueue.size;
      pqueue.heap[pqueue.size - 1] = new_element;
      pqueue.SiftUp(pqueue.size - 1);
    }
  }
}

int main() {
  int k = 0;
  std::cin >> k;
  int **arrs = new int *[k];
  int *sizes = new int[k];
  Pqueue pqueue;
  pqueue.heap = new Element[k];
  for (int i = 0; i < k; ++i) {
    int n = 0;
    std::cin >> n;
    arrs[i] = new int[n];
    sizes[i] = n;
    for (int j = 0; j < n; ++j) {
      std::cin >> arrs[i][j];
    }
    if (n > 0) {
      Element element;
      element.value = arrs[i][0];
      element.arr_index = i;
      element.own_index = 0;
      ++pqueue.size;
      pqueue.heap[pqueue.size - 1] = element;
      pqueue.SiftUp(pqueue.size - 1);
    }
  }
  int total_size = 0;
  for (int i = 0; i < k; ++i) {
    total_size += sizes[i];
  }
  int *res_arr = new int[total_size];
  int j = 0;
  Merge(arrs, pqueue, j, sizes, res_arr);
  for (int i = 0; i < total_size; ++i) {
    std::cout << res_arr[i] << " ";
  }
  for (int i = 0; i < k; ++i) {
    delete[] arrs[i];
  }
  while (pqueue.size != 0) {
  }
  delete[] res_arr;
  delete[] pqueue.heap;
  delete[] arrs;
  delete[] sizes;
  return 0;
}

void Pqueue::SiftDown(int i) {
  while (2 * i + 1 < size) {
    int child = 2 * i + 1;
    if (child + 1 < size && heap[child].value > heap[child + 1].value) {
      ++child;
    }
    if (heap[i].value > heap[child].value) {
      Swap(heap[child].value, heap[i].value);
      Swap(heap[child].arr_index, heap[i].arr_index);
      Swap(heap[child].own_index, heap[i].own_index);
      i = child;
    } else {
      break;
    }
  }
}

void Pqueue::SiftUp(int i) {
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].value > heap[i].value) {
      Swap(heap[parent].value, heap[i].value);
      Swap(heap[parent].arr_index, heap[i].arr_index);
      Swap(heap[parent].own_index, heap[i].own_index);
      i = parent;
    } else {
      break;
    }
  }
}
