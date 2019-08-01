#include <vector>

template <class T>
int bin(std::vector<T> v, T t, int l, int h) {
  int m;
  while(true) { 
    // invariant: t must be in [l, h] if exist
    if(l > h) return 0;

    m = l + (h-l) / 2;

    if     (v[m] < t) l = m + 1;
    else if(v[m] > t) h = m - 1;
    else              return m;
  }
}