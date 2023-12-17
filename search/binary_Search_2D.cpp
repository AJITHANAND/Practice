#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
    bool binary_search(vector<int>&arr,int target){
        int left = 0 , right = arr.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if (target == arr[mid]) return true;
            else if (target > arr[mid]) left = mid+1;
            else right = mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = matrix.size()-1; i >=0 ; i--) {
            if (target >= matrix[i][0] && target <= matrix[i][matrix[i].size()-1]){
                return binary_search(matrix[i],target);
            }
        }
        return false;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>>matrix{ {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    cout<<Solution().searchMatrix(matrix,13);
  
  
    return 0;
}