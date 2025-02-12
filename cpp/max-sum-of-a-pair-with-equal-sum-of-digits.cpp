#include<iostrea>
#include<vector>

using namespace std;

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            
            unordered_map<int, int> sumMap;
            int maxSum = -1;

            for (int num : nums) {
                int digitSum = 0;
                int temp = num;

                while (temp > 0) {
                    digitSum += temp % 10;
                    temp /= 10;
                }

                if (sumMap.count(digitSum)) {
                    maxSum = max(maxSum, sumMap[digitSum] + num);
                }
                sumMap[digitSum] = max(sumMap[digitSum], num);
            }

            return maxSum;
        }
};



int main(){
    Solution s;
    vector<int> nums = {55, 23, 32, 46, 88};
    cout << s.maximumSum(nums) << endl;
    return 0;

}