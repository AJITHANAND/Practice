#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n<3){
            return false;
        }
        int third = INT_MIN;
        stack<int>st;
        for(int i =n-1 ;i>=0;i--){
            if ( nums[i]< third ){
                return true;
            }
            while(!st.empty() && nums[i] > st.top()){
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>nums{3,1,4,2};
    Solution obj;
    cout<<obj.find132pattern(nums);
    return 0;
}