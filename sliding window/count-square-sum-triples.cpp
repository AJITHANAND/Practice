#include <iostream>
#include <vector>
class Solution {
private:
public:
  int countTriples(int n) {

    std::vector<bool> is_square(n * n + 1, false);
    for (int i = 1; i <= n; i++) {
      is_square[i * i] = true;
    }

    int count = 0;
    for (int a = 1; a < n; a++) {
      int a_sq = a * a;
      for (int b = a + 1; b < n; b++) {
        int c_square = a_sq + b * b;
        if (c_square > n * n)
          break;

        if (is_square[c_square]) {
          count += 2;
        }
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  int n = 5;
  std::cout << "Count of triples for n = " << n
            << " is: " << sol.countTriples(n) << std::endl;
  return 0;
}