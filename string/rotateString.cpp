#include<iostream>
using namespace std;


// Brute force solution O(n^2)
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(goal.size()!=s.size()){
//             return false;
//         }
//         if(s==goal){
//             return true;
//         }
//         int gIdx=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]==goal[gIdx]){
//                 gIdx++;
//                 for(int j=0;j<s.size();j++){
//                     if(s[(j+i+1)%s.size()]!=goal[gIdx]){
//                         break;
//                     }
//                     gIdx++;
//                 }
//                 if(gIdx==s.size()){
//                     return true;
//                 }
//                 gIdx=0;
//             }
//         }
//         return false;
//     }
// };

// Optimized solution O(n)

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()!=s.size()){
            return false;
        }
        if(s==goal){
            return true;
        }
        s+=s;
        return s.find(goal)!=string::npos;
    }
};

int main(){

    Solution s;
    cout<<s.rotateString("awuvupcrsatnwvxsdbonhyszidtchtisxbiqaekyervvjwfrakopukxbsoorjyioppbqhjmmjzvtjijbubhqhsdtsflvopozqufp","qufpawuvupcrsatnwvxsdbonhyszidtchtisxbiqaekyervvjwfrakopukxbsoorjyioppbqhjmmjzvtjijbubhqhsdtsflvopoz")<<endl;




    return 0;
}
