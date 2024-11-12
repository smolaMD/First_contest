#ifndef HEAP_S
#define HEAP_S

template <class T>
void Swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T> void SiftDown(T *begin, T *end, int i) {
  while (2 * i + 1 < end - begin) {
    int child = 2 * i + 1;
    if (child + 1 < end - begin && *(begin + child) < *(begin + child + 1)) {
      ++child;
    }
    if (*(begin + i) < *(begin + child)) {
      Swap(*(begin + child), *(begin + i));
      i = child;
    } else {
      break;
    }
  }
}

template <class T> void MakeHeap(T *begin, T *end) {
  for (int i = (end - begin - 1) / 2; i >= 0; --i) {
    SiftDown(begin, end, i);
  }
}

template <class T> void SortHeap(T *begin, T *end) {
  int h_size = end - begin;
  while (h_size > 1) {
    Swap(*begin, *(begin + h_size - 1));
    --h_size;
    SiftDown(begin, begin + h_size, 0);
  }
}

#endif
