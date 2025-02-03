#include <iostream>
using namespace std;


// brute force
// class Solution {
// public:
//     int longestMonotonicSubarray(vector<int>& nums) {
//         int incre = 0;
//         int decre = 0;
//         int i=0;
//         while(i<nums.size()-1){
//             if(nums[i] < nums[i+1]){
//                 int j = i ;
//                 while(j<nums.size()-1 && nums[j] < nums[j+1]){
//                     j++;
//                 }
//                 incre = max(incre, j-i+1);
//                 i = j;
//             }
//             i++;
//         }
//         i=0;
//         while(i<nums.size()-1){
//             if(nums[i] > nums[i+1]){
//                 int j = i ;
//                 while(j<nums.size()-1 && nums[j] > nums[j+1]){
//                     j++;
//                 }
//                 decre = max(decre, j-i+1);
//                 i = j;
//             }
//             i++;
//         }   
//         i = max(incre, decre);
//         return i == 0 ? 1 : i;
//     }
// };

// optimized
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int i = 0;
        while(i<n-1){
            int j = i;
            while(j<n-1 && nums[j] < nums[j+1]){
                j++;
            }
            ans = max(ans, j-i+1);
            i = j;
            while(j<n-1 && nums[j] > nums[j+1]){
                j++;
            }
            ans = max(ans, j-i+1);
            if (j == i) j++;
            i = j;
        }
        return ans;
    }
};



int main() {
    Solution sol;
    vector<int> nums = {1,4,3,3,2};
    cout << sol.longestMonotonicSubarray(nums) << endl;
    return 0;
}  