#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  long long sumAndMultiply(int n) {
    std::string str = "";
    long long sumOfDigits = 0;

    while (n > 0) {
      int digit = n % 10;
      if (digit != 0) {
        str = std::to_string(digit) + str;
        sumOfDigits += digit;
      }
      n /= 10;
    }
    long long concatenatedNumber = std::stoll(str.empty() ? "0" : str);
    return concatenatedNumber * sumOfDigits;
  }
};

int main() {
  Solution solution;
  int n = 10203004;
  long long result = solution.sumAndMultiply(n);
  assert(n == result);
  std::cout << "Test passed!" << std::endl;

  n = 0;
  result = solution.sumAndMultiply(n);
  assert(result == 0);
  std::cout << "Test passed!" << std::endl;
  return 0;
}