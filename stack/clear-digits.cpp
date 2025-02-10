#include <iostream>
using namespace std;


class Solution {
    public:
        string clearDigits(string s) {
            std::string output_stack="";
            int str_len=0;
            for(int i=0;i<s.size();i++){
                char current = s[i];
                output_stack += " ";
                if(isdigit(s[i])){
                    str_len--;
                    continue;
                }
                output_stack[str_len++]=current;

            }
            std::cout << output_stack << endl;
            std::cout << str_len << endl;
            return output_stack.substr(0,str_len);
        }
};

int main(){
    std::string str = "aa34";
    Solution s;
    std::string result = s.clearDigits(str);
    std::cout << result << endl; 
    return 0;
}