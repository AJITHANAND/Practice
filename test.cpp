#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isVectorInResult(const std::vector<std::vector<int>>& result, const std::vector<int>& temp) {
        std::unordered_set<int> tempSet(temp.begin(), temp.end());
        
        for (const std::vector<int>& innerVector : result) {
            if (innerVector.size() != temp.size()) {
                continue;
            }
            
            bool isEqual = true;
            for (int num : innerVector) {
                if (tempSet.find(num) == tempSet.end()) {
                    isEqual = false;
                    break;
                }
            }
            
            if (isEqual) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> result = {{0}};
    std::vector<int> temp = {4, 5, 6};

    Solution solution;
    bool found = solution.isVectorInResult(result, temp);

    if (found) {
        std::cout << "Vector found in the result." << std::endl;
    } else {
        std::cout << "Vector not found in the result." << std::endl;
    }

    return 0;
}
