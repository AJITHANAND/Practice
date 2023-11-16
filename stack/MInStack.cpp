#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class MinStack {
private:
    stack<int>s;
    map<int,int>minStack;
public:
    MinStack() {
    
    }
    
    void push(int val) {
        s.push(val);
        minStack[val]++;
    }
    
    void pop() {
        if(s.empty())return;
        int val =  top();
        if (minStack[val] >1){
            minStack[val]--;
        }else{
            minStack.erase(val);
        }
        s.pop();
    }
    
    int top() {
        if(s.empty())return -1;
        return s.top();
    }
    
    int getMin() {
        if(s.empty())return -1;
        for(auto i :minStack){
            return i.first;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    vector<string >args{"MinStack","push","push","push","getMin","pop","top","getMin"};
    vector<vector<int>>vals{{},{-2},{0},{-3},{},{},{},{},{}};
    MinStack* obj = new MinStack();
    for(int i=1;i<args.size();i++){
        if(args[i]=="push"){
            obj->push(vals[i][0]);
            cout<<"null,";
        }
        else if(args[i]=="pop"){
            obj->pop();
            cout<<"null,";
        }else if( args[i] == "top") {
            cout<<obj->top()<<",";
        }
        else if( args[i] == "getMin") {
            cout<<obj->getMin()<<",";
        }
    }
  
    return 0;
}