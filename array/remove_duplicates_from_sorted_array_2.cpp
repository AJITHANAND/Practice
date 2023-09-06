#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>result;
        int i =0;
        while(i<nums.size()){
            int temp = nums[i];
            int count =0;
            while(i<nums.size() && temp == nums[i]){
                if(count <2){
                    result.push_back(temp);
                    count++;
                }
                i++;
            }
        }
        nums =  result;
        return result.size();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int ans = s.removeDuplicates(arr);
    cout << ans << endl;
    for(auto i: arr){
        cout<<i<<" ";
    }
  
  
  
  
    return 0;
}