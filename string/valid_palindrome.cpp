#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        int left =0,right = s.length()-1;
        while (left<right){
            if(isalnum(s[left]) == false ){
                left++;
                continue;
            }
            if(isalnum(s[right]) == false ){
                right--;
                continue;
            }
            if(tolower(s[left]) !=  tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    cout<<s.isPalindrome("Marge, let's \"[went].\" I await {news} telegram.");
    
  
  
    return 0;
}