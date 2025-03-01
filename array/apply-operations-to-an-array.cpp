#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Solution {

    public:
        vector<int> applyOperations(vector<int>& nums) {
            vector<int>result;
            int numsZeros = 0;
            for(int i =0;i<nums.size();i++){
                if((i+1)<nums.size() && nums[i]==nums[i+1] && nums[i] != 0){
                    nums[i] = nums[i] * 2;
                    nums[i + 1] = 0;
                    result.push_back(nums[i]);
                } else if (nums[i] != 0) {
                    result.push_back(nums[i]);
                }
                if (nums[i] == 0) {
                    numsZeros++;
                }
            }
            for(int i = 0; i < numsZeros; i++){
                result.push_back(0);
            }
            
            return result; 
        }
    };


int main() {
    Solution s;
    vector<int> nums = {1, 2, 2, 1, 1, 0};
    vector<int> result = s.applyOperations(nums);
    vector<int> expected = {1, 4, 2, 0, 0, 0};
    cout << (result == expected ? "Test passed!" : "Test failed!") << endl;
    return 0;
}