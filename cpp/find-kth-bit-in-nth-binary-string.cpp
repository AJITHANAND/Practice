#include <iostream>
#include <string>

class Solution {
public:
  // O(n) time, O(n) stack — no string construction needed
  char findKthBit(int n, int k) {
    if (n == 1) return '0';

    int len = (1 << n) - 1;   // length of S_n = 2^n - 1
    int mid = (len / 2) + 1;  // 1-indexed middle position

    if (k == mid) return '1';
    if (k < mid) return findKthBit(n - 1, k);

    // k is in the right half → mirror position in S_{n-1}, then invert
    char bit = findKthBit(n - 1, len - k + 1);
    return bit == '0' ? '1' : '0';
  }
};

int main() {

  Solution sol;

  if (sol.findKthBit(3, 1) != '0') {
    std::cerr << "Test case 1 failed!" << std::endl;
  } else {
    std::cout << "Test case 1 passed!" << std::endl;
  }

  if (sol.findKthBit(4, 11) != '1') {
    std::cerr << "Test case 2 failed!" << std::endl;
  } else {
    std::cout << "Test case 2 passed!" << std::endl;
  }

  return 0;
}