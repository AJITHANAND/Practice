#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(const auto& i:strs){
            string temp = i;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        for(const auto& i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution obj;
    vector<vector<string>> res = obj.groupAnagrams(strs);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
    }

    
  
    return 0;
}