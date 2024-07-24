#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <cassert>
#include <string>
using namespace std;

// First Approach

// class Solution {
//     int StringToInt(string s){
//         int num = 0;
//         for(int i = 0;i<s.size();i++){
//             num = num*10 + (s[i] - '0');
//         }
//         return num;
//     }

// public:
//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         vector<int>output;
//         map<int,vector<int>>mp;

//         for(int i = 0;i<nums.size();i++){
//             string s ="";
//             string currentNum = to_string(nums[i]);
//             for(int j=0 ;j<currentNum.size();j++){
//                 s+=to_string(mapping[StringToInt(string(1,currentNum[j]))]);
//             }
//             mp[StringToInt(s)].push_back(nums[i]);
//         }
//         for(auto i:mp){
//             for (int j =0;j<i.second.size();j++){
//                 output.push_back(i.second[j]);
//             }
//         } 
//         return output;

//     }
// };

// Second Approach

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>output;
        map<int,vector<int>>mp;

        for(int i = 0;i<nums.size();i++){
            string s ="";
            string currentNum = to_string(nums[i]);
            for(int j=0 ;j<currentNum.size();j++){
                s+=to_string(mapping[currentNum[j]-'0']);
            }
            mp[stoi(s)].push_back(nums[i]);
        }
        for(auto i:mp){
            for (int j =0;j<i.second.size();j++){
                output.push_back(i.second[j]);
            }
        } 
        return output;

    }
};



int main(){
    /*
    Test Case 1:
    Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
    Output: [338,38,991]
    */ 
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = {991,338,38};
    vector<int> output = {338,38,991};
    assert(Solution().sortJumbled(mapping, nums) == output);
    cout<<"Test Case 1 Passed"<<endl;

    /*
    Test Case 2:
    Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
    Output: [123,456,789]
    */
    mapping = {0,1,2,3,4,5,6,7,8,9};
    nums = {789,456,123};
    output = {123,456,789};
    assert(Solution().sortJumbled(mapping, nums) == output);
    cout<<"Test Case 2 Passed"<<endl;




    return 0;
}
