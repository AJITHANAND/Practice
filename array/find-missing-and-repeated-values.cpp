#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            std::unordered_set<int>hashSet;
            int n = grid.size();
            int duplicate = -1;
            int sum = 0;
            for (auto &row : grid){
                for (auto &val : row){
                    if (duplicate == -1){
                        if (hashSet.find(val) != hashSet.end()){
                            duplicate = val;
                        }
                        hashSet.insert(val);
                    }
                    sum += val;
                }
            }
            int totalElements = grid.size() * grid[0].size();
            int Expectedsum = totalElements * (totalElements + 1) / 2;
            int missing = Expectedsum - (sum - duplicate);
            std::cout<<duplicate<<" "<<missing<<std::endl;

            return {duplicate, missing};

            
        }
    };

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)




int main(){
    Solution s;
    /*
    Example 1:
    Input: grid = [[1,3],[2,2]]  
    Output: [2,4]
    Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
    Example 2:

    Input: grid = [[9,1,7],[8,9,2],[3,4,6]] 
    Output: [9,5]
    Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
 */
    vector<vector<int>> grid = {{1,3},{2,2}};
    vector<int> res = s.findMissingAndRepeatedValues(grid);
    assert(res[0] == 2);
    assert(res[1] == 4);

    grid = {{9,1,7},{8,9,2},{3,4,6}};
    res = s.findMissingAndRepeatedValues(grid);
    assert(res[0] == 9);
    assert(res[1] == 5);
   

    return 0;
}