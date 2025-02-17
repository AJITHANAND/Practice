// letter-tile-possibilities

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
    private:
        int dfs(vector<int>& count) {
            int sum = 0;
            for (int i = 0; i < 26; i++) {
                if (count[i] == 0) {
                    continue;
                }
                sum++;
                count[i]--;
                sum += dfs(count);
                count[i]++;
            }
            return sum;
        }
    public:
        int numTilePossibilities(string tiles) {
            vector<int> count(26, 0);
            for (char c : tiles) {
                count[c - 'A']++;
            }
            return dfs(count);
        }
    };



int main(){
    Solution s;
    assert(s.numTilePossibilities("AAB") == 8);
    assert(s.numTilePossibilities("AAABBC") == 188);
    return 0;
}