// Given a sentence with numbers representing a word’s location in the sentence, embedded within each word, and return the sorted sentence. 

// Note: We are using a maximum of 0-9 numbers only for 1 sentence

// Example 1

// Input:  is1 Thi0s T3est 2a
// Output:  This is a Test

// Example 2

// Input:  t2o j3oin 4WonderBiz I0 Technolog5ies wan1t
// Output:  I want to join WonderBiz Technologies

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

map<int,string>mp;
void store(string str){
    string base = "";
    int idx;
    for (int i = 0; i < str.length(); i++){
        if (isdigit(str[i])){
            idx = str[i] - '0'; 
        }
        else{
            base += str[i];
        }
    }
    mp[idx] = base;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    getline(cin,str);
    stringstream ss(str);
    string word;
    while(ss>>word){
        store(word);
    }
    
    for(auto i = mp.begin();i!=mp.end();i++){
        cout<<i->second<< " ";
    }
  
  
    return 0;
}