#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#include <iostream>

// directions
const int DIR_X[]={0,1,0,-1};
const int DIR_Y[]={1,0,-1,0};

// more directions
// const int DIR_X[]={0,1,0,-1,1,1,-1,-1,0};
// const int DIR_Y[]={1,0,-1,0,-1,1,1,-1,0};

/*
 * check if the coordinate is valid
 * the number in matrix is 1 means this can be accessed
 */
bool isValid(const int row, const int col, const int ROW, const int COL,
             const std::vector<std::vector<int> >& matrix) {
  return ( (row >= 0) && (row < ROW) &&      
           (col >= 0) && (col < COL) &&       
           (matrix[row][col] == 1) );
}

/*
 * Run dfs on the given grid
 * Assume each row in grid has same length
 * 
 * grid is a matrix with only 0 and 1
 * 1 : accessible, 0 : unaccessible
 */ 
void dfs(const std::vector<std::vector<int> >& grid) {
  int idx = 0, ro = 0, co = 0, r = 0, c = 0, i = 0, j = 0, d = 0;
  const int ROW = grid.size(), COL = grid[0].size(); 

  std::vector<std::pair<int, int> > region =
      std::vector<std::pair<int, int> >();

  std::vector<std::vector<std::pair<int, int> > > regions =
      std::vector<std::vector<std::pair<int, int> > >();

  std::stack<std::pair<int,int> > st = std::stack<std::pair<int,int> >(); // stack
  std::vector<std::vector<int> > visited(grid); // 0 if visited or unable to visit
                                                // may be confusing, but save some memory

  for(i = 0; i < ROW; ++i) {
    for(j = 0; j < COL; ++j) {
      if(visited[i][j] == 0) continue;

      region.clear();

      st.push(std::make_pair(i,j));

      while(!st.empty()){
        r = st.top().first;
        c = st.top().second;
        st.pop();

        // visit
        visited[r][c] = 0;
        region.push_back(std::make_pair(r,c));

        for (d = 0; d < 4; ++d) { // 4 neighbors
          ro = r + DIR_X[d];
          co = c + DIR_Y[d];
          if (isValid(ro, co, ROW, COL, visited)) {
            st.push(std::make_pair(ro, co));
          }
        }
      }

      // std::sort(region[idx].begin(), region[idx].end());
      regions.push_back(region);
      ++idx;
    }
  }
}

int main() {
  return 0;
}