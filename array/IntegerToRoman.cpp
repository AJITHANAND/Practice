#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
  string intToRoman(int num) {
    vector<pair<string, int>> dict{
        {"I", 1},   {"IV", 4},   {"V", 5},    {"IX", 9},  {"X", 10},
        {"XL", 40}, {"L", 50},   {"XC", 90},  {"C", 100}, {"CD", 400},
        {"D", 500}, {"CM", 900}, {"M", 1000},
    };

    string result = "";
    for (int i = dict.size()-1; i >=0; i--) {
      if (num >= dict[i].second) {
        int count = num / dict[i].second;
        num = num % dict[i].second;
        for (int j = 0; j < count; j++) {
          result += dict[i].first;
        }
      }
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    Solution sol;
    cout<<sol.intToRoman(3999);
  return 0;
}