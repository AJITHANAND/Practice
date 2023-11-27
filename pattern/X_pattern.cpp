#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        for(int j=0;j<str.length();j++){
            if(i==j){
                cout<<str[i];
            }else if(i==str.length()-1-j){
                cout<<str[j];
            }else{
                cout<<" ";
            }
        }
        cout<<endl;

    }
  
  
  
    return 0;
}
