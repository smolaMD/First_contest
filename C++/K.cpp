#ifndef PQUEUE
#define PQUEUE

template <class T> void Swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T> void PushHeap(T *begin, T *end) {
  T *target = begin + (end - begin - 1);
  T *parent = begin + ((end - begin - 2) / 2);
  while (*parent < *target && begin < target) {
    Swap(*parent, *target);
    target = parent;
    parent = begin + (target - begin - 1) / 2;
  }
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

template <class T> void PopHeap(T *begin, T *end) {
  Swap(*begin, *(end - 1));
  SiftDown(begin, end - 1, 0);
}

#endif
