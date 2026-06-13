#include <iostream>
#include <vector>
using namespace std;

class Solution {

  inline int charToIndex(char ch) const { return ch - 'a'; }
  
  int wordToSum(const string& str, const vector<int>& weights) const {
    int sum = 0;
    for (char ch : str) {
      sum += weights[charToIndex(ch)];
    }
    return sum;
  }
  
  inline char AlphaIndexOfInt(int idx) const {
    return static_cast<char>('z' - idx);
  }

public:
  string mapWordWeights(const vector<string>& words, const vector<int>& weights) const {
    string out;
    out.reserve(words.size());
    for (const string& word : words) {
      out += AlphaIndexOfInt(wordToSum(word, weights) % 26);
    }
    return out;
  }
};

int main() {

  Solution s;

  vector<string> words = {"abcd", "def", "xyz"};

  vector<int> weight = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7,
                        8, 7, 10, 8,  9, 6, 9, 9, 8,  3, 7, 7, 2};

  if (s.mapWordWeights(words, weight) != "rij") {
    std::cout << "Test case Failed" << std::endl;
    return 1;
  }
  return 0;
}