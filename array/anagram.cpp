#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


bool isAnagram(string s, string t) {
    unordered_map<char,int>dict;
    if(s.length()!=t.length())
        return false;
    int i=0,j=0;

    while(i<s.length()){
        dict[s[i]]++;
        dict[t[i]]--;
        i++;
    }
    for(auto x:dict){
        if(x.second!=0){
            return false;
        }
    };
    return true;
        
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s ="anagram" ,t="nagaram";
    cout<<isAnagram(s,t);
    return 0;
}