#ifndef MER
#define MER

template <class T1, class T2, class T3>
void Merge(const T1 *first_begin, const T1 *first_end, const T2 *second_begin,
           const T2 *second_end, T3 *out) {
  while ((first_begin < first_end) && (second_begin < second_end)) {
    if (*first_begin < *second_begin) {
      *out = *first_begin;
      ++first_begin;
    } else {
      *out = *second_begin;
      ++second_begin;
    }
    ++out;
  }
  while (first_begin < first_end) {
    *out = *first_begin;
    ++first_begin;
    ++out;
  }
  while (second_begin < second_end) {
    *out = *second_begin;
    ++second_begin;
    ++out;
  }
}

#endif
