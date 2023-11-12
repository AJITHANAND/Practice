#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
        // int i =0;
        // for( ; i<nums.size();i++){
        //     if(target <=nums[i]){
        //         return i;
        //     }
        // }
        // return i;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {1,3,5,6};
    int target = 2;
    Solution s;
    cout<<s.searchInsert(nums,target);
    return 0;
}