#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
    private:
        long long operation(long long a , long long b) {
            return (min(a, b) * 2) + max(a, b);
        }
    public:
        int minOperations(vector<int>& nums, int k) {
            std::priority_queue<long long, vector<long long>, std::greater<long long>> minHeap(nums.begin(), nums.end());
            int count = 0;
            while (minHeap.size() > 1 && minHeap.top() < k) {
                long long a = minHeap.top();
                minHeap.pop();
                long long b = minHeap.top();
                minHeap.pop();
                long long sum = operation(a, b);
                minHeap.push(sum);
                count++;
            }
            return count;
            }
    };




int main(){
    Solution s;
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    assert(s.minOperations(nums, k) == 2);
    
    nums = {1,1,2,4,9};
    k = 20;
    assert(s.minOperations(nums, k) == 4);


    return 0;

}