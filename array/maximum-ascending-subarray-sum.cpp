#include <iostream>
using namespace std;



class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0;
        for(int i = 0;i<nums.size();i++){
            if(i == 0 || nums[i] > nums[i-1]){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};


int main(){
    Solution s;
    vector<int> nums = {10,20,30,5,10,50};
    cout << s.maxAscendingSum(nums) << endl;
    return 0;
}