#ifndef BIN_S
#define BIN_S

template <class T>
bool BinarySearch(const T *begin, const T *end, const T &value) {
  int i = -1;
  int j = end - begin;
  while (i < j - 1) {
    int mid = (i + j) / 2;
    if (*(begin + mid) < value) {
      i = mid;
    } else if (value < *(begin + mid)) {
      j = mid;
    } else {
      return true;
    }
  }
  return false;
}

template <class T>
const T *LowerBound(const T *begin, const T *end, const T &value) {
  int i = -1;
  int j = end - begin;
  while (i < j - 1) {
    int mid = (i + j) / 2;
    if (*(begin + mid) < value) {
      i = mid;
    } else {
      j = mid;
    }
  }
  return (begin + j);
}

template <class T>
const T *UpperBound(const T *begin, const T *end, const T &value) {
  int i = -1;
  int j = end - begin;
  while (i < j - 1) {
    int mid = (i + j) / 2;
    if (value < *(begin + mid)) {
      j = mid;
    } else {
      i = mid;
    }
  }
  return (begin + j);
}

#endif
