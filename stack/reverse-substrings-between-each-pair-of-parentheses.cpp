#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(auto i : s){
            if(i == ')'){
                vector<char>temp;
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                
                for(auto j : temp){
                    st.push(j);
                }
            }else{
                st.push(i);
            }
        }
        string result="";
        while(!st.empty()){
            result =st.top()+result;
            st.pop();
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.reverseParentheses("(u(love)i)");
    return 0;
}

