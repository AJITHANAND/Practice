#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>result ;
        for(int i =0;i<nums.size();i++){
            if (nums[i] != val){
                result.push_back(nums[i]);
            }
        }
        nums = result;
        return result.size();
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>nums = {3,2,2,3};
    Solution s;
    int ans  = s.removeElement(nums,3);
    for(auto i :nums){
        cout << i << " ";
    }

  
  
  
  
    return 0;
}