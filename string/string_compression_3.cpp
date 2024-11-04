#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string compressedString(string word) {
        if (word.size() == 1 ){
            return to_string(1) + word[0];
        }
        string out;
        int count=1;
        char mem=word[0];
        for(int i = 1 ;i<word.size();i++){
            if (word[i] == mem){
                if(count == 9){
                    out.push_back('9');
                    out.push_back(mem);
                    count = 1;
                }else{
                    count ++;
                }
            }else{
                out += to_string(count) + mem;
                mem = word[i];
                count = 1;
            }
        }
        return out + to_string(count) + mem;
    }
};



int main() {
    Solution sol;
    string word = "aaabbbccc";
    cout << sol.compressedString(word) << endl;
    return 0;
}
