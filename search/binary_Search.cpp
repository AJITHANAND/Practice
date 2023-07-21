#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


class Solution {
public:
    int binary_search(vector<int>& nums,int left, int right,int target){
        if (left>right){
            return -1;
        }
        int mid = (left + right)/2;
        if(nums[mid] == target){
            return mid;
        }
        if (nums[mid] < target){
            return binary_search(nums,mid+1,right,target);
        }
        if (nums[mid] > target){
            return binary_search(nums,left,mid-1,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums,0,nums.size()-1,target);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    vector<int>arr{-1,0,3,5,9,12};
    cout<<s.search(arr,9);
  
  
    return 0;
}