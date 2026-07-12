#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    std::set<int> unique(arr.begin(), arr.end());
    std::unordered_map<int, int> rankMap;
    int rank = 1;
    for (const int &num : unique) {
      rankMap[num] = rank++;
    }
    for (int &num : arr) {
      num = rankMap[num];
    }
    return arr;
  }
};

int main() {
  Solution s;
  vector<int> arr = {40, 10, 20, 30};
  vector<int> result = s.arrayRankTransform(arr);
  vector<int> expected = {4, 1, 2, 3};
  if (result == expected) {
    cout << "Test passed!" << endl;
  } else {
    cout << "Test failed!" << endl;
  }
  return 0;
}