#include <assert.h>
#include <bitset>
#include <iostream>
#include <string>
class Solution {

private:
  std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of('0');
    if (first == std::string::npos) {
      return "0";
    }
    return str.substr(first);
  }

public:
  int binaryGap(int n) {
    std::string value = std::bitset<32>(n).to_string();
    value = trim(value);
    int maxGap = 0;
    for (int i = 0; i < value.size(); i++) {
      if (value[i] == '1') {
        int gap = 0;
        bool found = false;
        for (int j = i + 1; j < value.size(); j++) {
          gap++;
          if (value[j] == '1') {
            found = true;
            break;
          }
        }
        if (found) {
          maxGap = std::max(gap, maxGap);
        }
      }
    }
    return maxGap;
  }
};

void TestCase(int n, int expected) {
  int result = Solution().binaryGap(n);
  try {
    if (result != expected) {
      throw std::runtime_error("Test failed");
    }
    std::cout << "Test passed for n = " << n << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Test failed for n = " << n << ": expected " << expected
              << ", got " << result << std::endl;
  }
}

int main() {
  TestCase(8, 0);
  TestCase(5, 2);
  TestCase(22, 2);
  return 0;
}