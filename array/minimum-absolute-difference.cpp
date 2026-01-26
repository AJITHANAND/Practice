#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    vector<vector<int>> result;

    for (size_t i = 1; i < arr.size(); i++) {
      int diff = arr[i] - arr[i - 1];
      if (diff < minDiff) {
        result.clear();
        result.push_back({arr[i - 1], arr[i]});
        minDiff = diff;
      } else if (diff == minDiff) {
        result.push_back({arr[i - 1], arr[i]});
      }
    }

    return result;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {4, 2, 1, 3};
  vector<vector<int>> result = sol.minimumAbsDifference(arr);

  for (const auto &pair : result) {
    cout << "[" << pair[0] << ", " << pair[1] << "] ";
  }
  cout << endl;

  return 0;
}