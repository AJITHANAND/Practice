#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class MinStack {
private:
    stack<pair<int,int>>s;
    int curr_min;
public:
    MinStack() {
        curr_min = INT_MAX;
    }
    
    void push(int val) {
        curr_min = min(curr_min,val);
        s.push(pair<int,long int>(val,curr_min));
    }
    
    void pop() {
        if(s.empty())return;
        s.pop();
        curr_min = s.empty() ? INT_MAX : s.top().second;
    }
    
    int top() {
        if(s.empty())return -1;
        return s.top().first;
    }
    
    int getMin() {
        if(s.empty())return -1;
        return s.top().second;
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
  
    vector<string >args{"MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"};
    vector<vector<int>>vals{ {},{2147483646},{2147483646},{2147483647},{},{},{},{},{},{},{2147483647},{},{},{-2147483648},{},{},{},{}  };
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