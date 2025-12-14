#include <iostream>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    std::string result;
    result.reserve(std::max(a.size(), b.size()) + 1);

    while (i >= 0 || j >= 0 || carry) {
      int sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';
      result.push_back((sum % 2) + '0');
      carry = sum / 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution solution;
  std::string a = "1010";
  std::string b = "1011";
  std::string result = solution.addBinary(a, b);
  std::cout << "The sum of " << a << " and " << b << " is: " << result
            << std::endl;
  return 0;
}