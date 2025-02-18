// construct-smallest-number-from-di-string
#include <iostream>
#include <cassert>
using namespace std;


class Solution {
    public:
        string smallestNumber(string pattern) {
            string result;
            vector<int> st;
            int num = 1;
            for (int i = 0; i <= pattern.size(); i++) {
                st.push_back(num++);
                if (i == pattern.size() || pattern[i] == 'I') {
                    while (!st.empty()) {
                        result += to_string(st.back());
                        st.pop_back();
                    }
                }
            }
            return result;
        }
    };

int main() {



    Solution sol;
    assert(sol.smallestNumber("IIIDIDDD")=="123549876");
    assert(sol.smallestNumber("III")=="123");
    assert(sol.smallestNumber("DDI")=="321");


    return 0;
}