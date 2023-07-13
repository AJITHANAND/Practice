#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}


int solve(vector<int>&arr,int n){
    int count=0;
    int total =arr[0];
    for (int  i = 0; i < n; i++)
    {
        if (isPrime(arr[i])){
            count +=1;
        }
        if (i==0){
            continue;
        }
        total ^=arr[i];
    }
    (isPrime(total)) ? count+=1 : count;
    return count%(int)(pow(10,9) +7);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int size;
        cin>>size;
        vector<int> arr(size);
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        cout<<solve(arr,size)<<endl;
    }
    return 0;
}