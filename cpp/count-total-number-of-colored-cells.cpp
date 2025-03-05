#include <iostream>
#include <cassert>
using namespace std;


class Solution {
    public:
        long long coloredCells(int n) {
            return pow(n-1,2) + pow(n,2);
        }
    };


int main(){
    Solution s;
    assert(s.coloredCells(1) == 1);
    assert(s.coloredCells(2) == 5);
    return 0;
}