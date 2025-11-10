#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int midVal(int left, int right) { return left + (right - left) / 2; }

  int recSearch(std::vector<int> &arr, int left, int right, int target) {
    if (left > right) {
      return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      return recSearch(arr, left, mid - 1, target);
    } else {
      return recSearch(arr, mid + 1, right, target);
    }
  }
  int splitPoint(std::vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;
    if (arr[left] < arr[right]) {
      return 0;
    }
    while (left < right) {
      int mid = midVal(left, right);
      if (mid < right && arr[mid] > arr[mid + 1]) {
        return mid + 1;
      }
      if (mid > left && arr[mid] < arr[mid - 1]) {
        return mid;
      }
      if (arr[mid] >= arr[left]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return 0;
  }

public:
  int search(vector<int> &nums, int target) {
    int beginVal = nums[0];
    int lastVal = nums[nums.size() - 1];

    int smalletPoint = splitPoint(nums);
    if (nums[smalletPoint] == target) {
      return smalletPoint;
    }
    if (target > nums[smalletPoint] && target <= nums[nums.size() - 1]) {
      return recSearch(nums, smalletPoint, nums.size() - 1, target);
    } else {
      return recSearch(nums, 0, smalletPoint - 1, target);
    }
  }
};

int main() {
  std::vector<int> arr = {4, 5, 6, 7, 8, 9, 0, 1, 2};
  Solution s;

  std::cout << "Position : " << s.search(arr, 3) << std::endl;

  return 0;
}