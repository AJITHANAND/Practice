#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int length = nums.size();
    vector<vector<int>> result;
    for (int i = 0; i < length; i++) {
      if(i>0 && nums[i-1] == nums[i])
        continue;
      int left = i + 1;
      int right = length - 1;
      int target = -nums[i];
      while (left < right) {
        int t_sum = nums[left] + nums[right];
        if (t_sum < target) {
          left++;
        } else if (t_sum > target) {
          right--;
        } else {
          result.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;
          left++;
          right--;
        }
      }
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> input{-2, 0, 1, 1, 2};
  Solution st;
  vector<vector<int>> result = st.threeSum(input);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < 3; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}