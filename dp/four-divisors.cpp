#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {

private:
  int sumOfDivisorsOf4(int num) {
    int count = 0;
    int sum = 0;
    for (int i = 1; i * i <= num; ++i) {
      if (num % i == 0) {
        count++;
        sum += i;
        if (i != num / i) {
          count++;
          sum += num / i;
        }
      }
      if (count > 4) {
        return 0;
      }
    }
    return (count == 4) ? sum : 0;
  }

public:
  int sumFourDivisors(vector<int> &nums) {
    std::map<int, int> memo;
    int totalSum = 0;
    for (int num : nums) {
      if (memo.find(num) != memo.end()) {
        totalSum += memo[num];
      } else {
        int sumDiv = sumOfDivisorsOf4(num);
        memo[num] = sumDiv;
        totalSum += sumDiv;
      }
    }
    return totalSum;
  }
};

int main() {
  std::vector<int> nums = {21, 4, 7};
  Solution sol;
  int result = sol.sumFourDivisors(nums);
  std::cout << "Result: " << result << std::endl;
  return 0;
}