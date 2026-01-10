#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    std::vector<std::vector<int>> dp(s1.size() + 1,
                                     std::vector<int>(s2.size() + 1, 0));
    for (int i = 1; i <= s1.size(); ++i) {
      dp[i][0] = dp[i - 1][0] + static_cast<int>(s1[i - 1]);
    }
    for(int j = 1; j<=s2.size() ; j++){
        dp[0][j] = dp[0][j-1] + static_cast<int>(s2[j-1]);
    }

    for( int row = 1; row <= s1.size(); row++){
        for( int col = 1 ; col <=s2.size();col++){
            if(s1[row-1] == s2[col-1]){
                dp[row][col] = dp[row-1][col-1];
            }else{
                dp[row][col] = std::min(
                    dp[row-1][col] + static_cast<int>(s1[row-1]),
                    dp[row][col-1] + static_cast<int>(s2[col-1])
                );
            }
        }
    }

    return dp[s1.size()][s2.size()];    
  }
};

int main() { return 0; }