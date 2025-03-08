#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int minimumRecolors(string blocks, int k) {
//         std::queue<char>window;
// 	int minimum = INT_MAX;
// 	int currentWhiteCount = 0;
// 	for(int i =0;i<blocks.size();i++){
// 		if (window.size() == k ){
// 			minimum = std::min(minimum,currentWhiteCount);
// 			if(window.front() == 'W'){
// 				currentWhiteCount--;
// 			}
// 			window.pop();
// 		}
// 		if(blocks[i] == 'W'){
// 			currentWhiteCount++;
// 		}
// 		window.push(blocks[i]);
// 	}
// 	minimum = std::min(minimum,currentWhiteCount);
// 	return minimum;
//     }
// };

class Solution {
	public:
		int minimumRecolors(string blocks, int k) {
			int n = blocks.size();
			int whiteCount = 0;
			for (int i = 0; i < k && i < n; i++) {
				if (blocks[i] == 'W') {
					whiteCount++;
				}
			}
			int minWhiteCount = whiteCount;
			for (int i = k; i < n; i++) {
				if (blocks[i - k] == 'W') {
					whiteCount--;
				}
				
				if (blocks[i] == 'W') {
					whiteCount++;
				}
				minWhiteCount = min(minWhiteCount, whiteCount);
			}
			
			return minWhiteCount;
		}
	};
	

int main(){

	Solution s;
	cout<<s.minimumRecolors("BBBWW",2)<<endl;
	cout<<s.minimumRecolors("BBBWW",3)<<endl;
	cout<<s.minimumRecolors("WWWW",2)<<endl;
	
	
	return 0;

}
