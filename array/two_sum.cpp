#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> solve (vector<int> &nums, int target) {
    // vector<int>seen;
    // int pos=0;
    // for(int i : nums){
    //     auto idx = std::find(seen.begin(), seen.end(),i);
    //     if (idx != seen.end()){
    //         return vector<int>{(int)(idx-seen.begin()),pos};
    //     }
    //     seen.push_back(target-i);
    //     pos++;
    // }
    // return vector<int>{0};

    unordered_map<int,int>seen;
    for (int i= 0; i < nums.size(); ++i) {
        if(seen.find(nums[i]) != seen.end()){
            return vector<int>{seen[nums[i]],i};
        }
        seen[target-nums[i]]=i;
    }
    return vector<int>{0};

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr{2,5,5,11};
    for(auto i : solve(arr,10)){
        cout<<i<<" ";
    }
  
    return 0;
}