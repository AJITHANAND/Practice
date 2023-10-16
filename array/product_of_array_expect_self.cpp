#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
    
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int>ans;
//         int product =1;
//         bool containZero = false;
//         bool doubleZero = false;
//         for(auto const &i: nums){
//             if(i!=0){
//                 product *= i;
//             }
//             if(i==0){
//                 if(containZero){
//                     doubleZero = true;
//                 }
//                 containZero =true;
                
//             }
//         }
//         for(auto const& i: nums){
//             if(doubleZero){
//                 ans.push_back(0);
//             }
//             else if(i!=0 && !containZero){
//                 ans.push_back(product/i);
//             }
//             else if(i!=0 && containZero){
//                 ans.push_back(0);
//             }
//             else if(i==0 && containZero){
//                 ans.push_back(product);
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>prefix(n,1);
//         vector<int>postfix(n,1);
//         vector<int>ans;
//         int pre=1,post=1;
//         for(int val= 0; val < n-1; val++){
//             pre *= nums[val];
//             post *= nums[n-val-1];
//             prefix[val + 1] = pre;
//             postfix[n-val-2] = post;
//         }
//         for(int val = 0;val<prefix.size();val++){
//             ans.push_back(prefix[val]*postfix[val]);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int pre=1,post=1;
        for(int val= 0; val < n-1; val++){
            pre *= nums[val];
            ans[val+1]*=pre;
        }
        for(int val = n-1;val>0;val--){
            post *= nums[val];
            ans[val-1] *= post;
        }

        return ans;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // vector<int>arr{-1,1,0,-3,3};
    // vector<int>arr{0,0};
    vector<int>arr{1,2,3,4};
    vector<int>ans=Solution().productExceptSelf(arr);
    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}