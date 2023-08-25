#include<bits/stdc++.h>
using namespace std;

int largestSubarray(int input1,int input2[]){
    unordered_map<int, int> mp;
    int sum = 0; 
    int max_len = 0; 
    int end_idx = -1;       
    for (int i = 0; i < input1; i++) {

        sum += (input2[i] =input2[i] == 0) ? -1 : 1;
        if (sum == 0) {
            max_len = i + 1;
            end_idx = i;
        }
        if (mp.find(sum) != mp.end()) {
            if (max_len < i - mp[sum]) {
                max_len = i - mp[sum];
                end_idx = i;
            }
        }
        else 
        {
            mp[sum] = i;
        }
    }
    return max_len;
}

















The average weight of six persons is increased by 2.5 lbs when one of them, whose weight is 50 lbs. is replaced by a new man. What is the weight of the new man?

options :
65,75,76,60