#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
#define endl '\n'

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



class Solution {
public:
    vector<string> generateParenthesis(int n) {

        string current;
        std::vector<std::string> result;
        generate(0, 0, current,n, result);
        return result;
    }


private:
    void generate(int open , int close , std::string &current ,int total , std::vector<std::string> &result){
        if (open == total && close == total) {
            result.push_back(current);
            return;
        }
        if (open < total) {
            current.push_back('(');
            generate(open + 1, close, current, total, result);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            generate(open, close + 1, current, total, result);
            current.pop_back();
        }
    }
};


int main() { 

    Solution s ;
    std::vector<std::string> result = s.generateParenthesis(3);

    for (const auto& str : result) {
        std::cout << str << endl;
    }

    return 0;
}