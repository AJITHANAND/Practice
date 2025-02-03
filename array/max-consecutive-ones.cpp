#include <iostream> 
using namespace std;    

// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int count = 0;
//         if (nums[0] == 1){
//             count++;
//         }
//         if (nums.size() == 1){
//             return count;
//         }
//         int i = 0;
//         while(i <nums.size()){
//             if (nums[i] == 1){
//                 int temp = i;
//                 while(i < nums.size() && nums[i] == 1){
//                     i++;
//                 }
//                 count = max(count, i - temp);
//             }else{
//                 i++;
//             }
//         }
//         return count;
//     }
// };

// more optimized solution

class Solution {    
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1){
                count++;
            }else{
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        return max(maxCount, count);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}