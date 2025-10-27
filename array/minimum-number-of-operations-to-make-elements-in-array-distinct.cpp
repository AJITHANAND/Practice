#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    vector<bool>seen(128);
    for(int i = nums.size() -1 ; i >= 0; i--) {
      if(seen[nums[i]]) {
        return i/3 +1 ;
      } else {
        seen[nums[i]] = true;
      }
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> nums = {4, 5, 6, 4, 4};
  cout << s.minimumOperations(nums) << endl; // Output:
  return 0;
}