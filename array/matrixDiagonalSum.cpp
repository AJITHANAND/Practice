#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0,len=mat.size()-1;
        for ( int i=0;i<=len;i++){
            sum += mat[i][i];
            if (i == len-i)continue;
            sum += mat[i][len-i];
        }
        return sum;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    cout<<obj.diagonalSum(mat);
  
  
    return 0;
}