#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if (arr.empty())
            return 0;
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        return arr.size();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int ans = s.removeDuplicates(arr);
    cout << ans << endl;
    for(auto i: arr){
        cout<<i<<" ";
    }
  
  
  
  
    return 0;
}