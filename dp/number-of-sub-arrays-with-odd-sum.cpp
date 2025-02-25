#include <iostream>
using namespace std;


class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    for(int i = 0; i<n; i++) {
      for(int j = i; j<n; j++) {
        int sum = 0;
        for(int k = i; k <= j; k++) {
            sum += arr[k];
        }
        if (sum % 2 != 0) {
            count++;
        }
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  vector<int> arr = {1, 3, 5};
  cout << s.numOfSubarrays(arr) << endl;
  return 0;
}
