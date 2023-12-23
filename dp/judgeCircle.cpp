#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

bool judgeCircle(const string& moves) {
    int x = 0, y = 0;
    for(char c : moves){
        switch(c){
            case 'U': y++; break;
            case 'D': y--; break;
            case 'L': x--; break;
            case 'R': x++; break;
        }
    }
    return x == 0 && y == 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string tc_1 ="UL",
           tc_2 ="UD",
           tc_3 ="UDLR";
    
    cout<< (judgeCircle(tc_2) ? "passed" : "failed") <<endl;
    cout << (judgeCircle(tc_1) ? "failed" : "passed") <<endl;
    cout << (judgeCircle(tc_3) ? "passed" : "failed") <<endl;
  
    return 0;
}