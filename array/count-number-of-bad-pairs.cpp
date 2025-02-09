#include <iostream>
#include <vector>

using namespace std;

// Brute force solution
// class Solution {
//     bool isBadPair(int a, int b, int Val_a, int Val_b) {
//         if(a > b) {
//             return false;
//         }
//         if (b - a != Val_b - Val_a) {
//             return true;
//         }
//         return false;
//     }
//     public:
//         long long countBadPairs(vector<int>& nums) {
//             long long count = 0;
//             for(int i=0;i<nums.size();i++) {
//                 for(int j=i+1;j<nums.size();j++) {
//                     if(isBadPair(i, j, nums[i], nums[j])) {
//                         count++;
//                     }
//                 }
//             }
//             return count;
//             }
// };

// Optimized time complexity solution

// find a group of pairs that are good , means they have same difference in their values and indexes


class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long totalPairs = 0;
            long long goodPairs = 0;
            std::unordered_map<int,int> slope;
            for(int i = 0; i < nums.size(); i++) {
                totalPairs += i;
                goodPairs += slope[nums[i] - i];
                slope[nums[i] - i]++;
            }
            return totalPairs - goodPairs;
        }
};


int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.countBadPairs(nums) << endl;
    return 0;
}