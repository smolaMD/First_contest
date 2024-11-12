#ifndef SORT
#define SORT

template <class T>
void Sort(T *begin, T *end) {
  if (end - begin < 2) {
    return;
  }
  T *i = begin;
  T *j = end - 1;
  T pivot = *(begin + (end - begin) / 2);
  while (i - 1 < j) {
    while (*i < pivot) {
      ++i;
    }
    while (pivot < *j) {
      --j;
    }
    if (i - 1 < j) {
      T tmp = *i;
      *i = *j;
      *j = tmp;
      ++i;
      --j;
    }
  }
  Sort(begin, j + 1);
  Sort(i, end);
}

#endif
