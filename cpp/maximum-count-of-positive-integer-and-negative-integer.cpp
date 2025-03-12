#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int positive=0,negative=0;
            for (auto i : nums){
                if (i<0){
                    negative++;
                }else if(i >0){
                    positive++;
                }
            }
            return std::max(positive,negative);
        }
    };


int main() {
    Solution sol;
    vector<int> nums = {1, -2, -3, 4};
    cout << sol.maximumCount(nums) << endl;
    return 0;
}
