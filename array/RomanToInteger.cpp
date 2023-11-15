#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>dict{
           { 'I', 1},
            {'V', 5},
           {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int total = 0;
        for(int i =0 ; i<s.size();i++){
            if(dict[s[i]]<dict[s[i+1]]){
                total-=dict[s[i]];
            }else{
                total += dict[s[i]];
            }
        }
        return total;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str = "IV";
    Solution sol;
    cout<<sol.romanToInt(str);
  
  
  
    return 0;
}