#include<vector>
#include<string>
#include<algorithm>

#include<iostream>

#define MAX_CHAR 257                     // ASCII
#define chatInt(c) (int)(unsigned char)c // type casting, not recommended

/**
 * A naive implementation of using radix sort to sort str (ASCII)
 * a: array of strings to sort
 * n : number of strings to sort
 * len: longest length to sort
 */
void radixSortStr(std::vector<std::string>& a, int n, int len) {
  for(int idx = len - 1; idx >= 0; --idx) {              // sort index by index
    std::vector<int> cnt = std::vector<int>(MAX_CHAR,0); // count, from bucket sort
    std::vector<std::string> ans(n);                     // ans

    // count the bucket
    for(int i = 0; i < n; ++i) {
      // if too short: push_front ([0])
      // else: get the int value of char ([0])
      cnt[idx < a.at(i).size() ? chatInt(a.at(i).at(idx)) + 1 : 0] += 1;
    }

    // sum from the previous slot
    for(int i = 1; i <= MAX_CHAR; ++i) {
      cnt[i] += cnt[i - 1];
    }

    // reversely build the ans vector
    for(int i = n - 1; i >= 0; --i) {
      ans.at(cnt[idx < a.at(i).size() ? chatInt(a.at(i).at(idx)) + 1 : 0]-- - 1) = a.at(i);
    }

    // apply changes
    for(int i = 0; i < n; ++i) {
      a.at(i) = ans.at(i);
    }
  }
}

int main() {
  std::vector<std::string> a = {"some","omeso","z","b","b","e","abc","acd","zab","atoip","ax","qx","az","qqq","gxzc","ytr","xzcqwe","azzz"};
  int len = 4; // only sort by first 4 characters

  radixSortStr(a, a.size(),len);

  for(const auto & x : a) {
      std::cout<<x<<std::endl;
  }
}