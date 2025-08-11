#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    std::vector<int> memo(n + 1, -1);
    return climb(n, memo);
  }

private:
  int climb(int n, std::vector<int> &memo) {
    if (n <= 1)
      return 1;
    if (memo[n] != -1)
      return memo[n];
    return memo[n] = climb(n - 1, memo) + climb(n - 2, memo);
  }
};

int main() {
  Solution sol;
  assert(sol.climbStairs(2) == 2);
  std::cout << "Test Case 1 Passed" << std::endl;
  assert(sol.climbStairs(3) == 3);
  std::cout << "Test Case 2 Passed" << std::endl;
  assert(sol.climbStairs(4) == 5);
  std::cout << "Test Case 3 Passed" << std::endl;
  assert(sol.climbStairs(5) == 8);
  std::cout << "Test Case 4 Passed" << std::endl;
  return 0;
}
