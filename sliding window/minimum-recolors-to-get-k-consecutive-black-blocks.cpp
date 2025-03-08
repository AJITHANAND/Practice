#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        std::queue<char>window;
	int minimum = INT_MAX;
	int currentWhiteCount = 0;
	for(int i =0;i<blocks.size();i++){
		if (window.size() == k ){
			minimum = std::min(minimum,currentWhiteCount);
			if(window.front() == 'W'){
				currentWhiteCount--;
			}
			window.pop();
		}
		if(blocks[i] == 'W'){
			currentWhiteCount++;
		}
		window.push(blocks[i]);
	}
	minimum = std::min(minimum,currentWhiteCount);
	return minimum;
    }
};

int main(){

	Solution s;
	cout<<s.minimumRecolors("BBBWW",2)<<endl;
	cout<<s.minimumRecolors("BBBWW",3)<<endl;
	cout<<s.minimumRecolors("WWWW",2)<<endl;
	
	
	return 0;

}
