#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
given set of numbers, find a pair of numbers that add upto certain target. Ex given [1,2,3,9]
and a target of 10 , identify that 1 and 9 add upto 10,
*/





//============================ Brute force ===============================

bool brute_force(vector<int>arr,int sum,int n){
    for(int i=0;i<n;i++){
        for (int j = i+1;j<n;j++){
            if (arr[i] + arr[j] == sum){
                return true;
            }
        }
    }
    return false;
}

//============================= Binary Search ============================= 

bool binary_search(vector<int>&arr,int val,int min,int max){
    if(min > max){
        return false;
    }
    int mid = (min+max)/2;
    if (arr[mid]==val){
        return true; 
    }
    else if (arr[mid]<val){
        return binary_search( arr,val,mid+1,max);
    }
    else if (arr[mid] > val){
        return binary_search(arr,val,min,mid-1);
    }

    return false;
}

bool value_search(vector<int>arr,int sum,int n){
    for(int i =0 ;i<n;i++){
        int comp  = sum - arr[i];
        if(binary_search(arr,comp,i,n-1)){
            return true;
        }
    }
    return false;
}

//============================= linear solution ============================= 

bool optimal_comp(vector<int>&arr,int sum,int n){
    int min=0,max=n-1,t_sum;
    while(min<max){
        
        t_sum = arr[min]+arr[max];
        // cout<<"min :"<<min<<"\tmax :"<<max<<"\tt_sum :"<<t_sum<<"\tsum :"<<sum<<endl;
        if (sum == t_sum){
            return true;
        }
        else if( t_sum > sum){
            max--;
        }
        else if(t_sum <sum){
            min++;
        }
    }
    return false;
}


bool solve(vector<int>arr,int sum , int n){
    // return brute_force(arr,sum,n);
    // return value_search(arr,sum,n);
    return optimal_comp(arr,sum,n);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count,sum,i=0,temp;
    vector<int>arr;
    cin>>count>>sum;
    for(;i<count;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<(solve(arr,sum,count)?"Yes, pair exits":"No, pair doesn't exists")<<endl;
  
  
    return 0;
}


