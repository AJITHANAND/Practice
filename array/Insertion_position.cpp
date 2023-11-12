#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i =0;
        for( ; i<nums.size();i++){
            if(target <=nums[i]){
                return i;
            }
        }
        return i;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {1,3,5,6};
    int target = 5;
    Solution s;
    cout<<s.searchInsert(nums,target);
    return 0;
}