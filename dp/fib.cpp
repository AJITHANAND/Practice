#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<long long int> dp{0,1};

void fib(int n){
   
    if (dp.size() >n){
        cout<<dp[n]<<endl;
        return;
    }
    for(int i=dp.size();i<=n;i++){
        dp.push_back(dp[i-1]+dp[i-2]);
    }
    cout<<dp[n]<<endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    for(int i =0;i<=50;i++){
        fib(i);
    }
    
    for(auto i : dp){
        cout<<i<<" ";
    }
    return 0;
}
