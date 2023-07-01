#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
hackerrank : https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem

find out triplet which satisfy a>=b>=c & b+c>a

*/



vector<int> solve (vector<int>arr,int n){
    sort(arr.begin(),arr.end());
    int last = arr.size()-1,second,first;
    while(last>1){
        second = last -1;
        first=second-1;
        if ((arr[first]<=arr[second]<=arr[last]) && (arr[first]+arr[second]>arr[last])){
            return vector<int>{arr[first],arr[second],arr[last]};
        }
        last--;
    }
    return vector<int>{-1};
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int temp,size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int>result = solve(arr,size);
    for(auto i:result){
        cout<<i<<" ";
    }
  
    return 0;
}