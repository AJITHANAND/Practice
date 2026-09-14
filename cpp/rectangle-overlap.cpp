#include <iostream>
#include <vector>

class Solution {
public:
  bool isRectangleOverlap(std::vector<int> &rec1, std::vector<int> &rec2) {
    int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
    int p1 = rec2[0], q1 = rec2[1], p2 = rec2[2], q2 = rec2[3];

    if (q1 >= y2 || x1 >= p2 || y1 >= q2 || p1 >= x2) {
      return false;
    }
    return true;
  }
};

int main() {
  std::vector<int> r1{0, 0, 2, 2};
  std::vector<int> r2{1, 1, 3, 3};

  Solution s;

  if (s.isRectangleOverlap(r1, r2) == true) {
    std::cout << "TestCase passed" << std::endl;
  } else {
    std::cout << " TestCase failed" << std::endl;
  }

  std::vector<int> r3{0, 0, 1, 1};
  std::vector<int> r4{1, 0, 2, 1};

  if (s.isRectangleOverlap(r3, r4) == false) {
    std::cout << "TestCase passed" << std::endl;
  } else {
    std::cout << "TestCase failed" << std::endl;
  }

  std::vector<int> r5{0, 0, 1, 1};
  std::vector<int> r6{2, 2, 3, 3};

  if (s.isRectangleOverlap(r5, r6) == false) {
    std::cout << "TestCase passed" << std::endl;
  } else {
    std::cerr << "TestCase Failed" << std::endl;
  }
}
