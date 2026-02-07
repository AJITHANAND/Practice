#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int minimumDeletions(string s) {
    stack<char> st;
    int minDeletion = 0;
    for (char c : s) {
      if (!st.empty() && (st.top() == 'b' && c == 'a')) {
        st.pop();
        minDeletion++;
      } else {
        st.push(c);
      }
    }
    return minDeletion;
  }
};

int main() {
  Solution s;
  std::cout << " Minimum deletion for aababbab : "
            << s.minimumDeletions("aababbab") << std::endl;

  return 0;
}