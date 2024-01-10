#include<bits/stdc++.h>
using namespace std;

void backtrack(string input, string curr, int length, vector<string>& ans) {
    if (length == 4 && input.empty()) {
        ans.push_back(curr.substr(0, curr.size()-1));
        return;
    }
    if (length == 4 || input.empty()) return;
    for(int i=1; i<=3; i++){
        if(input.size() < i) break;
        string part = input.substr(0, i);
        if((part.size() > 1 && part[0] == '0') || stoi(part) > 255) continue;
        backtrack(input.substr(i), curr+part+".", length+1, ans);
    }
}

vector<string> genIpAddresses(string input) {
    vector<string> ans;
    backtrack(input, "", 0, ans);
    return ans;
}

void print(vector<string> &output){
    for(int i=0; i<output.size(); i++){
        cout << output[i] << endl;
    }
}

int main(){
    string input = "111111";
    vector<string> output = genIpAddresses(input);
    print(output);
    return 0;
}
