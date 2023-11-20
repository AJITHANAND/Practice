#include<bits/stdc++.h>
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
    int missingNumber(vector<int>& nums) {
        return (nums.size()*(nums.size() + 1 ))/2 - accumulate(nums.begin(),nums.end(),0);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout<<Solution().missingNumber(nums)<<endl;
  
  
    return 0;
}