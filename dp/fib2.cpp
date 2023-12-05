#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
public:
    int fib(int n) {

        // dynamic programming memorization
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i =2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];


        //  recursion
        // if(n==0)return 0;
        // else if (n==1) return 1;
        // return fib(n-1) + fib(n-2);


        // normal

        // if(n<1){
        //     return 0;
        // }
        // int first = 0,second=1,sum=1;
        // for( int i =2;i<n;i++){
        //     sum +=second;
        //     int temp = first +second;
        //     first =second;
        //     second =temp;
        // }
        // return sum;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout<<Solution().fib(4);
  
  
  
    return 0;
}