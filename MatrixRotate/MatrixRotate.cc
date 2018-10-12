/**
 * author: snowme34@gmail.com
 * a 12-line O(n^2) and O(1) space algorithm to rotate a square matrix with size n*n
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <random>
#include <limits>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

#define INTMAX std::numeric_limits<int>::max()
#define WIDTH 4
#define UPPER_BOUND_DIST INTMAX>>24

// assume square matrix
void rotate(vector<vector<int> >& m) {
  int n = m[0].size(), idx = 0, tmp;
  while(n>1) {
    for(int i = idx+n-1; i > idx; --i) {
      tmp = m[idx][i];
      m[idx][i] = m[idx+n-(i-idx)-1][idx];
      m[idx+n-(i-idx)-1][idx] = m[idx+n-1][idx+n-(i-idx)-1];
      m[idx+n-1][idx+n-(i-idx)-1] = m[i][idx+n-1];
      m[i][idx+n-1] = tmp;
    }
    n -= 2;
    idx += 1;
  }
} 

void printVec(vector<vector<int> >& vec) {
  for (auto row : vec) {
    for (auto col : row) cout << setw(WIDTH) << col << " ";
    cout << endl;
  }
}

void runTest(vector<vector<int> >& vec) {
  cout << "before: \n";
  printVec(vec);
  rotate(vec);
  cout << "\nafter: \n";
  printVec(vec);
#ifndef NDEBUG
  cout << "TIME ELAPSED: " << ((float)clock()) / CLOCKS_PER_SEC << endl;
#endif
  cout << endl;
}

void generateMat(vector<vector<int> >& mat, int n) {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0,UPPER_BOUND_DIST);
  std::fill_n(std::back_inserter(mat), n, vector<int>(n,0));
  for(auto& row:mat) for(auto& c:row) c = dist(rng);
}

int main() {
  cout << "see demo?[Y/n]\n";
  std::string ans;
  cin >> ans;
  if(ans != "n") {
    vector<vector<int> > vec;
    vec = {{3, 6, 9}, {2, 5, 8}, {1, 4, 7}};
    runTest(vec);
    vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    runTest(vec);
    vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    runTest(vec);
    vec = {{1, 2, 3, 4, 5},
           {6, 7, 8, 9, 10},
           {11, 12, 13, 14, 15},
           {16, 17, 18, 19, 20},
           {21, 22, 23, 24, 25}};
    runTest(vec);
  }

  int n;
  cout << "enter a size: \n";
  cin >> n;
  if(n <= 0 || 2048 < n) {
    cout << "too large or too small" << endl;
    return 0;
  }
  vector<vector<int> > mat;
  generateMat(mat,n);
  runTest(mat);

  return 0;
}
