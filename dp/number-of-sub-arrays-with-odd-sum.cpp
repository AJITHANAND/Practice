#include <iostream>
using namespace std;

// Bruteforce solution
// class Solution {
// public:
//   int numOfSubarrays(vector<int> &arr) {
//     int n = arr.size();
//     int count = 0;
//     for(int i = 0; i<n; i++) {
//       for(int j = i; j<n; j++) {
//         int sum = 0;
//         for(int k = i; k <= j; k++) {
//             sum += arr[k];
//         }
//         if (sum % 2 != 0) {
//             count++;
//         }
//       }
//     }
//     return count;
//   }
// };

// dp solution

class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int n = arr.size();
    long long count = 0;
    int odd = 0;
    int even = 1;
    long long sum = 0;
    for(int i = 0; i<n; i++) {
      sum += arr[i];
      if (sum % 2 == 0) {
        count += odd;
        even++;
      } else {
        count += even;
        odd++;
      }
    }
    return count % 1000000007;
  }
};

int main() {
  Solution s;
  vector<int> arr = {1, 3, 5};
  cout << s.numOfSubarrays(arr) << endl;
  return 0;
}
