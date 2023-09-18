#include<bits/stdc++.h>
using namespace std;
#define endl "\n"



int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for(string s;getline(cin,s);out<<"\n"){
        if(s.length() == 2){
            out<<0;
            continue;
        }
        unordered_set<int>arr;
        s = s.substr(1,s.size()-2);
        std::stringstream ss(s);
        for(int i;ss>>i;){
            arr.insert(i);
            if(ss.peek() == ',')
                ss.ignore();
        }
        int length=0;
        for(const int i:arr){
            if (arr.find(i-1) == arr.end()){
                int temp =1,j=i+1;
                while(arr.find(j++)!=arr.end())
                    temp++;
                length = max(length,temp);
            }
        }
        out<<length;
    }
    out.flush();
    exit(0);
    return(0);
}();



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>arr(nums.begin(),nums.end());
        int length=0;
        for(const int i:arr){
            if (arr.find(i-1) == arr.end()){
                int temp =1,j=i+1;
                while(arr.find(j++)!=arr.end())
                    temp++;
                length = max(length,temp);
            }
        }
        return length;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int>arr {0,3,7,2,5,8,4,6,0,1};
    Solution st;
    cout<<st.longestConsecutive(arr);
  
    return 0;
}