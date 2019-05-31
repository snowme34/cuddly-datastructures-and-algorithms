#include <utility>
#include <vector>
#include <queue>
#include <iostream>

// line flood fill
int ff(int i, int j, int t, int r, std::vector<std::vector<int>>& A) {
    if(t == r) return 0;
    if(A[i][j] != t) return 0;
    
    std::queue<std::pair<int,int> > q;
    q.emplace(std::make_pair(i,j));
    
    int x, yw, ye, ans = 0;
    while(!q.empty()) {
        x = q.front().first, yw = ye = q.front().second;
        q.pop();
        while(A[x][yw] == t) yw-=1; while(A[x][ye] == t) ye+=1;
        while(++yw < ye) {
            A[x][yw] = r;
            ans += 1;
            if(x > 0          && A[x-1][yw] == t) q.emplace(std::make_pair(x-1,yw));
            if(x < A.size()-1 && A[x+1][yw] == t) q.emplace(std::make_pair(x+1,yw));
        }
    }
    return ans;
}

int main() {
  std::vector<std::vector<int> > test =
    {{0,0,0},
     {0,1,0},
     {1,1,0}};
  std::cout << ff(1,1,1,0,test) << "\n";
  return 0;
}