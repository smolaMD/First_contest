#include <iostream>

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

struct Pqueue {
  int *heap = nullptr;
  int size = 0;
  int capasity = 0;

  int SiftDown(int i);
  int SiftUp(int i);
};

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  Pqueue pqueue;
  pqueue.heap = new int[n];
  pqueue.capasity = n;
  for (int i = 0; i < m; ++i) {
    int type = 0;
    std::cin >> type;
    if (type == 1) {
      if (pqueue.size == 0) {
        std::cout << -1 << '\n';
      } else if (pqueue.size == 1) {
        std::cout << 0 << " " << pqueue.heap[0] << '\n';
        --pqueue.size;
      } else {
        int tmp_max = pqueue.heap[0];
        pqueue.heap[0] = pqueue.heap[pqueue.size - 1];
        --pqueue.size;
        std::cout << pqueue.SiftDown(0) + 1 << " " << tmp_max << '\n';
      }
    }
    if (type == 2) {
      int value = 0;
      std::cin >> value;
      if (pqueue.size >= pqueue.capasity) {
        std::cout << -1 << '\n';
      } else {
        ++pqueue.size;
        pqueue.heap[pqueue.size - 1] = value;
        std::cout << pqueue.SiftUp(pqueue.size - 1) + 1 << '\n';
      }
    }
    if (type == 3) {
      int i = 0;
      std::cin >> i;
      if (i > pqueue.size || i < 1) {
        std::cout << -1 << '\n';
      } else {
        std::cout << pqueue.heap[i - 1] << '\n';
        pqueue.heap[i - 1] = pqueue.heap[pqueue.size - 1];
        --pqueue.size;
        if (i - 1 < pqueue.size) {
          if (i - 1 == pqueue.SiftDown(i - 1)) {
            pqueue.SiftUp(i - 1);
          }
        }
      }
    }
  }
  for (int i = 0; i < pqueue.size; ++i) {
    std::cout << pqueue.heap[i] << " ";
  }
  delete[] pqueue.heap;
  return 0;
}

int Pqueue::SiftDown(int i) {
  while (2 * i + 1 < size) {
    int child = 2 * i + 1;
    if (child + 1 < size && heap[child] < heap[child + 1]) {
      ++child;
    }
    if (heap[i] < heap[child]) {
      Swap(heap[child], heap[i]);
      i = child;
    } else {
      break;
    }
  }
  return i;
}

int Pqueue::SiftUp(int i) {
  while (i > 0) {
    int parent = (i - 1) / 2;

    if (heap[parent] < heap[i]) {
      Swap(heap[parent], heap[i]);
      i = parent;
    } else {
      break;
    }
  }
  return i;
}
