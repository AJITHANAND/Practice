#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
  void populateCount(const vector<vector<int>> &grid, vector<int> &count) {
    for (int i = 0; i < grid.size(); i++) {
      int c = 0;
      for (int j = grid[i].size() - 1; j >= 0; j--) {
        if (grid[i][j] == 0) {
          c++;
        } else {
          break;
        }
      }
      count[i] = c;
    }
  }

public:
  int minSwaps(const vector<vector<int>> &grid) {
    vector<int> count(grid.size(), 0);
    populateCount(grid, count);

    int swaps = 0;
    for (int i = 0; i < count.size(); i++) {
      int j = i;
      while (j < count.size() && count[j] < count.size() - 1 - i) {
        j++;
      }
      if (j == count.size()) {
        return -1;
      }
      while (j > i) {
        swap(count[j], count[j - 1]);
        j--;
        swaps++;
      }
    }
    return swaps;
  }
};

int main() {
  // Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
  // Output: 3

  Solution sol;
  if (sol.minSwaps({{0, 0, 1}, {1, 1, 0}, {1, 0, 0}}) != 3) {
    cout << "Test case failed!" << endl;
    return -1;
  }

  return 0;
}