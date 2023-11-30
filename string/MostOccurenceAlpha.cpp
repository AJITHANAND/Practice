#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str = "interview",replace;
    int n = str.length();
    char output;
    int count = 0;
    for(int i = 0; i < n; i++){
        replace = "";
        char ch = str[i];
        int temp = 0;
        for(int j = 0;j<str.length();j++){
            if (str[j] == ch){
                temp++;
            }else{
                replace += str[j];
            }
        }
        if (count < temp){
            count = temp;
            output = ch;
        }else if (count == temp && output > ch){
            output = ch;
        }
        str = replace;
    }
    
    cout<<output;
  
  
    return 0;
}