#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

// return pair (L, U)
// such that v[L,U] (inclusive) sums closest to zero
std::pair<int, int> ss(const std::vector<int>& v) {
  int n = v.size();

  // cu[i] = sum(v[0...i-1])
  // second of pair keeps track of original index
  std::vector<std::pair<int, int> > cu(n + 1, std::make_pair(0,0));

  // guard
  cu[0] = std::make_pair(0, -1);

  for(int i = 0; i < n; ++i) {
    cu[i+1] = std::make_pair(cu[i].first + v[i], i);
  }

  std::sort(cu.begin(), cu.end());

  // v[L...U] sums to ZERO if cu[L-1] = cu[U]
  int minDiff = std::numeric_limits<int>::max();
  std::pair<int, int> ans;
  for(int i = 1; i <= n; ++i) {
    int newDiff = std::abs(cu[i].first-cu[i-1].first);
    if(newDiff < minDiff) {
      minDiff = newDiff;
      ans = std::make_pair(cu[i-1].second + 1, cu[i].second);
    }
  }
  return ans;
}

// TODO
// closest sum to t
// instead of scanning consecutive elements, binary search for cu[L-1] = cu[U] - t

int main() {
  int t, num;
  std::vector<int> v;
  // std::cout << "input t" << std::endl;
  // std::cin >> t;
  std::cout << "input array ended with EOF (ctrl D)" << std::endl;
  while(std::cin >> num) { v.push_back(num); }
  auto ans = ss(v);
  std::cout << "Answer Index: " << ans.first << " " << ans.second << std::endl;
  return 0;
}