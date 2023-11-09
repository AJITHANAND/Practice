#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int right  = digits.size()-1,rem=0,status=0,last=digits[right]+1,temp;
        vector<int>final(digits.size(),0);
        while(right>=0){
            temp = last + rem;
            rem = temp /10;
            final[right] = temp %10;
            right--;
            if(right>=0){
                last = digits[right];
            }
        }
        if(rem){
            final.insert(final.begin(),rem);
        }
        return final;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> digits = {9,9,9};
    vector<int> final = sol.plusOne(digits);
    for(auto i:final){
        cout<<i<<" ";
    }
  
  
  
  
    return 0;
}