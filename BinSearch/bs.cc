#include <iostream>
#include <vector>

// following is a few contract-based implementations of binary search

// the most standard binary search
// return idx of any t if exists
// return -1 otherwise
// in range [l, h)
template <class T>
int bs(const std::vector<T>& v, T t, int l, int h) {
  h--; // make invariant hold
  while(true) { 
    // invariant: t in [l, h] if exist
    if(l > h) return -1;
    int m = l + ((h-l) >> 1);
    if     (v[m] < t) l = m + 1;
    else if(v[m] > t) h = m - 1;
    else              return m;
  }
}

// return idx of first elem that is larger or equal to t (or h if not found)
// in range [l, h)
template <class T>
int bsf(const std::vector<T>& v, T t, int l, int h) {
  --l; // make invaliant hold, never access (e.g. v[-1])
  while(l+1 != h) { 
    // invariant: v[l] < t && v[h] >= t && l < h
    int m = l + ((h-l) >> 1);
    if (v[m] < t) l = m;
    else          h = m;
  }
  // l+1 == h && v[l] < t && v[h] >= t
  return h;
}

// return idx of last elem that is smaller or equal to t (or l-1 if not found)
// in range [l, h)
template <class T>
int bsl(const std::vector<T>& v, T t, int l, int h) {
  // 0 <= l <= h <= v.size()
  while(l < h) { 
    int m = l + ((h-l) >> 1);
    if (t < v[m]) h = m;     // [l,   m)
    else          l = m + 1; // [m+1, h)
  }
  // v[l-1] <= t && v[l] > t
  return l - 1;
}

int main() {
  int n, a;
  std::cout << "input array size: \n";
  std::cin >> n;
  std::vector<int> v(n);
  std::cout << "input ascending sorted array: \n";
  for(auto& e:v) std::cin>>e;

  std::cout << "input search value: \n";
  std::cin >> a;

  std::cout << "Binary search: " << bs(v, a, 0, n) << "\n";
  std::cout << "First elem larger or equal to: " << bsf(v, a, 0, n) << "\n";
  std::cout << "Last elem smaller or equal to: " << bsl(v, a, 0, n) << "\n";

  return 0;
}