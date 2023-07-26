#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        map<char,char>opposite{
            {'}','{'},
            {')','('},
            {']','['}
        };
        int n = s.length();
        if(n%2!=0)
            return false;
        for(int i=0;i<n;i++){
            if ( (! st.empty()) && st.top() == opposite[s[i]]  ){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    cout<<s.isValid("()");
  
  
  
    return 0;
}