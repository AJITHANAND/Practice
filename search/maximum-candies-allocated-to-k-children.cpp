#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k){
        int totalCandies = 0;
        int n = candies.size();
        for (int candy : candies){
            totalCandies += candy;
        }
        if ( totalCandies < k){
            return 0;
        }
        int upperLimit = totalCandies / k;
        int lowerLimit = 1;
        int maxCandies = 0;
        while(lowerLimit <= upperLimit){
            int mid = lowerLimit + (upperLimit - lowerLimit) / 2;
            if (isValid(candies, mid, k)){
                maxCandies = mid;
                lowerLimit = mid + 1;
            } else {
                upperLimit = mid - 1;
            }
        }
        return maxCandies;
    }

    bool isValid(vector<int> &candies, int mid, long long k) {
        long long total = 0;
        for (int candy : candies){
            total += candy / mid;
        }
        return total >= k;
    }
};

int main() {
    Solution s;
    vector<int> candies = {5,8,6};
    cout << s.maximumCandies(candies, 3) << endl;
    return 0;
}