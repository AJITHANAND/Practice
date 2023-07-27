#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>window;
        int res=0;
        for(int i=0;i<s.length();i++){
            auto it = find(window.begin(),window.end(),s[i]);
            if (it != window.end()){
                window.erase(window.begin(),it+1);
            }
            window.push_back(s[i]);
            res = max((int)window.size(),res);
        }
        return res;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
  
  
  
    return 0;
}