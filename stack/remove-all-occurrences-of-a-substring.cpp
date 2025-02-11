#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            vector<char> stack;
            for (char c : s) {
                stack.push_back(c);
                if (stack.size() >= part.size()) {
                    bool match = true;
                    for (int i = 0; i < part.size(); i++) {
                        if (stack[stack.size() - part.size() + i] != part[i]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        for (int i = 0; i < part.size(); i++) {
                            stack.pop_back();
                        }
                    }
                }
            }
            string result = "";
            for (char c : stack) {
                result += c;
            }
            return result;
        }
};



int main() {

    Solution solution;
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = solution.removeOccurrences(s, part);
    cout << result << endl;
    
    return 0;
}