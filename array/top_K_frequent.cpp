#include<bits/stdc++.h>
using namespace std;
#define endl "\n"



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>store;
        map<int,vector<int> >mp;
        for(auto const &i : nums){
            store[i]++;
        }
        for(auto const &i : store){
            mp[i.second].push_back(i.first);
        }
        vector<int>ans;
        for(auto i = mp.rbegin();i!=mp.rend()&&ans.size()<k;i++){
            ans.insert(ans.end(),i->second.begin(),i->second.end());
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> store;
//         priority_queue<pair<int,int>> pq;
//         vector<int> ans;
        
//         for(auto i : nums){
//             store[i]++;
//         }
        
//         for(auto i : store){
//             pq.push({i.second, i.first});
//             if(pq.size() > (int)store.size() - k){
//                 ans.push_back(pq.top().second);
//                 pq.pop();
//             }
//         }
        
//         return ans;
//     }
// };




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>nums{4,1,-1,2,-1,2,3};
    int k =2;

    Solution obj;
    vector<int>ans = obj.topKFrequent(nums,k);
    for(auto i:ans){
        cout << i << endl;
    }
  
  
  
    return 0;
}