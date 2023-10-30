#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0,i=0,j=height.size()-1;
        while(i<j){
            area = max(area,(min(height[i],height[j])*(j-i)));
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return area;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout <<sol.maxArea(height) << endl;    
  
  
    return 0;
}