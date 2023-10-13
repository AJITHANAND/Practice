#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void printNums(int n){
    if (n >10)return;
    cout<<n<<endl;
    return printNums(n+1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    printNums(1);
    
  
  
  
    return 0;
}