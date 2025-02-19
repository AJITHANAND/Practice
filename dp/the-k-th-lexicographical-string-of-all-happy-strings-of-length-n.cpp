#include <cassert>
#include <iostream>
#include <vector>



// recursive solution
class Solution {
    private:
        void generateHappyStrings(int n, std::string s, std::vector<std::string>& res) {
            if (s.size() == n) {
                res.push_back(s);
                return;
            }
            for (char c = 'a'; c <= 'c'; c++) {
                if (s.empty() || s.back() != c) {
                    s.push_back(c);
                    generateHappyStrings(n, s, res);
                    s.pop_back();
                }
            }
        }
    public:
        std::string getHappyString(int n, int k) {
            std::vector<std::string> res;
            generateHappyStrings(n, "", res);
            return k <= res.size() ? res[k - 1] : "";
        }
};



// Maths solution

// class Solution {

//   public:
//     string getHappyString(int length, int kth) {
//       int totalHappyStrings = 3 * (1 << (length - 1));
//       if (kth > totalHappyStrings) {
//         return "";
//       }
      
//       string result = "";
//       int stringsPerLetter = 1 << (length - 1);

//       // Determine the first character from 'a', 'b', 'c'
//       for (char letter : {'a', 'b', 'c'}) {
//         if (kth <= stringsPerLetter) {
//           result.push_back(letter);
//           break;
//         } else {
//           kth -= stringsPerLetter;
//         }
//       }

//       for (int pos = 1; pos < length; pos++) {
//         stringsPerLetter /= 2;
//         vector<char> choices;
//         for (char letter : {'a', 'b', 'c'}) {
//           if (letter != result.back()) {
//             choices.push_back(letter);
//           }
//         }
//         for (char letter : choices) {
//           if (kth <= stringsPerLetter) {
//             result.push_back(letter);
//             break;
//           } else {
//             kth -= stringsPerLetter;
//           }
//         }
//       }

//       return result;
//     }
// };

int main() {
  Solution s;
  assert(s.getHappyString(1, 3) == "c");
  assert(s.getHappyString(1, 4) == "");
  assert(s.getHappyString(3, 9) == "cab");

  std::cout << "Happy string with length = 1 and kth = 3: " << s.getHappyString(1, 3) << "\n";
  std::cout << "Happy string with length = 1 and kth = 4: " << s.getHappyString(1, 4) << "\n";
  std::cout << "Happy string with length = 3 and kth = 9: " << s.getHappyString(3, 9) << "\n";
  return 0;
}