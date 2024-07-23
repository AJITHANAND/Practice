#include<iostream>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

//  my first approach
// class Solution {
//     int maxToLeft(vector<int>&arr,const int& pos){
//         int maxHeight = arr[pos];
//         for(int i = pos ; i>=0;i--){
//             maxHeight = max(arr[i],maxHeight);
//         }
//         return maxHeight;
//     }
//     int maxToRight(vector<int>&arr,const int& pos){
//         int maxHeight = arr[pos];
//         for(int i = pos ; i<arr.size();i++){
//             maxHeight = max(arr[i],maxHeight);
//         }
//         return maxHeight;
//     }
// public:
//     int trap(vector<int>& height) {
//         int trappedWater = 0;
//         for (int i = 1;i<height.size()-1;i++){
//             trappedWater += min(maxToLeft(height,i),maxToRight(height,i)) - height[i];
//         }
//         return trappedWater;
//     }
// };

// store the max height to the left and right of the current position

// class Solution {
// public:
//     int trap(vector<int>&height){
//         int trappedWater = 0 ;
//         vector<int> maxLeft(height.size(),0) , maxRight(height.size(),0);

//         for(int i = 1 ; i<height.size();i++){
//             maxLeft[i] = max(maxLeft[i-1],height[i-1]);
//         }
//         for (int i = height.size() - 1 ; i >= 0 ; i--){
//             maxRight[i] = max(maxRight[i+1],height[i+1]);
//         }

//         for (int i = 1 ; i<height.size()-1;i++){
//             trappedWater += max(0,min(maxLeft[i],maxRight[i]) - height[i]);
//         }
//         return trappedWater;

//     }

// };

// two pointer approach
class Solution {
public:
    int trap(vector<int>&height){
        int trappedWater = 0;
        int left = 0 , right = height.size()-1,leftMax = height[left] , rightMax = height[right];
        while (left < right){

            if(leftMax < rightMax){
                left ++;
                leftMax = max(leftMax,height[left]);
                trappedWater += max(0,leftMax - height[left]);
            }else{
                right --;
                rightMax = max(rightMax,height[right]);
                trappedWater += max(0,rightMax - height[right]);
            }
        }
        return trappedWater;
    }

};



int main(){

    // Test Case : 1
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // assertion
    // Output: 6
    assert(Solution().trap(height) == 6);
    cout<<"Test Case 1 Passed"<<endl;

    // Test Case : 2
    height = {4,2,0,3,2,5};
    // assertion
    // Output: 9
    assert(Solution().trap(height) == 9);
    cout<<"Test Case 2 Passed"<<endl;


    return 0;
}
