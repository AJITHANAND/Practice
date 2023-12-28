#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


class Solution {
    void backtrack( vector<int> & nums , vector<vector<int>> &solution , vector<int>perms ){
        if (perms.size() == nums.size()){
            solution.push_back(perms);
            return;
        }
        for(auto num : nums){
            if (find(perms.begin(), perms.end(), num) == perms.end()){
                perms.push_back(num);
                backtrack(nums, solution, perms);
                perms.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> perms;
        backtrack(nums, solution, perms);
        return solution;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> solution = s.permute(nums);
    for(auto i : solution){
        for(auto j : i){
            cout<<j<<" ";
        }
    }
  
  
  
    return 0;
}