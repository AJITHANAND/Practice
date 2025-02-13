#include<iostream>
using namespace std;


// Brute Force Solution
// class Solution {
// public:
//     bool isCircularSentence(string str) {
//         if (str.size() < 2) {
//             return true;
//         }
//         for (int i = 1; i < str.size(); i++) {
//             if (str[i]==' ') {
//                 if (str[i-1] != str[(i+1)]){
//                     return false;
//                 }
//             }else if (i == str.size()-1){
//                 if (str[i] != str[0]) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

// Optimized Solution C++17 string_view

class Solution {
public:
    bool isCircularSentence(string_view str) {
        if (str.size() < 2) {
            return true;
        }
        if (str.back() != str.front()) {
            return false;
        }

        size_t pos = str.find(' ');
        while (pos != string::npos) {
            if (str[pos-1] != str[pos+1]) {
                return false;
            }
            pos = str.find(' ', pos+1);
        }
        return true;
    }
};


int main() {
    Solution sol;
    string str = "leetcode exercises sound delightful";
    cout << sol.isCircularSentence(str) << endl;
    return 0;
}
