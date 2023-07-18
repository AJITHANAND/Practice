#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();



int maxProfit(vector<int>& prices) {
    int left=0,right = 1,maxProfit=0,profit;
    for(;right<prices.size();right++){
        if(prices[left]<prices[right]){
            maxProfit = max( (prices[right]-prices[left]) , maxProfit );
        }
        else
            left = right;
    }
    return maxProfit;
}



int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<(maxProfit(prices));
  
  
  
  
    return 0;
}