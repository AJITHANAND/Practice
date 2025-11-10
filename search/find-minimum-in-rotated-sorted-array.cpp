#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int findMin(vector<int> &nums) {
    if (nums[0] < nums[nums.size() - 1]) {
      return nums[0];
    }
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (mid < right && nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }
      if (mid > left && nums[mid] < nums[mid - 1]) {
        return nums[mid];
      }
      if (nums[mid] >= nums[left]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return nums[0];
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << "Minimum in rotated sorted array: " << sol.findMin(nums) << endl;
  return 0;
}