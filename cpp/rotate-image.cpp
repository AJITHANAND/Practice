#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  void transpose(vector<vector<int>> &matrix, const size_t &n) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + 1; j < n; j++) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
  void reverseMatrix(vector<vector<int>> &matrix, const size_t &n) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n / 2; j++) {
        std::swap(matrix[i][j], matrix[i][n - j - 1]);
      }
    }
  }

public:
  void rotate(vector<vector<int>> &matrix) {
    size_t n = matrix.size();
    transpose(matrix, n);
    reverseMatrix(matrix, n);
  }
};

int main() {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.rotate(matrix);
  for (const auto &row : matrix) {
    for (const auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}