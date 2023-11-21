#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>store;
        for(int i =0 ; i<tokens.size();i++){
            if (tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*"){
                store.push(stoi(tokens[i]));                
            }
            else{
                int num1 = store.top();
                store.pop();
                int num2 = store.top();
                store.pop();
                switch((char)tokens[i][0]){
                    case '+':  store.push(num1+num2); break;
                     case '-':  store.push(num1-num2); break;
                      case '*':  store.push(num1*num2); break;
                       case '/':  store.push(num2/num1); break;
                }
            }
        }
        return store.top();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> tokens = {"4","13","5","/","+"};
    cout<<Solution().evalRPN(tokens);
    return 0;
}