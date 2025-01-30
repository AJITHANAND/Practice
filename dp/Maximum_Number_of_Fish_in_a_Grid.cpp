#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Brute force

// class Solution {
//   int traverse(vector<vector<int> > &grid, int row, int col) {
//     if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
//         grid[row][col] == 0) {
//       return 0;
//     }
//     int fish = grid[row][col];
//     grid[row][col] = 0;
//     map<string, bool> mp = adjacent(grid, row, col);
//     if (mp["top"]) {
//       fish += traverse(grid, row - 1, col);
//     }
//     if (mp["right"]) {
//       fish += traverse(grid, row, col + 1);
//     }
//     if (mp["bottom"]) {
//       fish += traverse(grid, row + 1, col);
//     }
//     if (mp["left"]) {
//       fish += traverse(grid, row, col - 1);
//     }
//     return fish;
//   }
//   map<string, bool> adjacent(vector<vector<int> > &grid, int row, int col) {
//     map<string, bool> mp;
//     if ((row - 1) >= 0 && grid[row - 1][col] != 0) {
//       mp["top"] = true;
//     } else {
//       mp["top"] = false;
//     }
//     if ((col + 1) < grid[0].size() && grid[row][col + 1] != 0) {
//       mp["right"] = true;
//     } else {
//       mp["right"] = true;
//     }
//     if (row + 1 < grid.size() && grid[row + 1][col] != 0) {
//       mp["bottom"] = true;
//     } else {
//       mp["bottom"] = false;
//     }
//     if (col - 1 >= 0 && grid[row][col - 1] != 0) {
//       mp["left"] = true;
//     } else {
//       mp["left"] = false;
//     }
//     return mp;
//   }

// public:
//   int findMaxFish(vector<vector<int> > &grid) {
//     int maxFish = 0;
//     for (int i = 0; i < grid.size(); i++) {
//       for (int j = 0; j < grid[0].size(); j++) {
//         if (grid[i][j] != 0) {
//           int fish = traverse(grid, i, j);
//           maxFish = max(maxFish, fish);
//         }
//       }
//     }
//     return maxFish;
//   }
// };

// Optimized

class Solution {
  int traverse(vector<vector<int> > &grid, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
        grid[row][col] == 0) {
      return 0;
    }
    int fish = grid[row][col];
    grid[row][col] = 0;
    fish += traverse(grid, row - 1, col);
    fish += traverse(grid, row, col + 1);
    fish += traverse(grid, row + 1, col);
    fish += traverse(grid, row, col - 1);
    return fish;
  }
public:
  int findMaxFish(vector<vector<int> > &grid) {
    int maxFish = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] != 0) {
          int fish = traverse(grid, i, j);
          maxFish = max(maxFish, fish);
        }
      }
    }
    return maxFish;
  }
};

int main() {
  Solution s;
  vector<vector<int>> grid = {{0, 1, 0, 0, 0},
                              {0, 1, 0, 0, 0},
                              {0, 1, 0, 0, 0},
                              {0, 1, 0, 0, 0},
                              {0, 1, 0, 0, 0}};
  cout << s.findMaxFish(grid) << endl;
  return 0;
}