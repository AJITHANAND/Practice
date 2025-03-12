#include <iostream>
using namespace std;


class Solution {
    public:
        int numberOfSubstrings(string s) {
            
            int count = 0, left = 0, right = 0;
            int n = s.length();
            int char_count[3] = {0}; // count of 'a', 'b', and 'c'

            while (right < n) {

                char_count[s[right] - 'a']++;
                while (char_count[0] > 0 && char_count[1] > 0 && char_count[2] > 0) {

                    count += n - right;

                    char_count[s[left] - 'a']--;
                    left++;
                }
                right++;
            }

            return count;
        }
    };


int main() {
    Solution sol;
    string s = "abcabc";
    cout << sol.numberOfSubstrings(s) << endl;
    return 0;
}
