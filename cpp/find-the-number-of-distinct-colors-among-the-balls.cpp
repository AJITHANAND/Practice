#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            std::unordered_map<int, int> indexToColor;
            std::unordered_map<int, int> colorCount;
            vector<int> result;
            for(int i =0; i< queries.size(); i++){
                int color = queries[i][1];
                int index = queries[i][0];
                
                if(indexToColor.find(index) != indexToColor.end()){
                  int oldColor = indexToColor[index];
                  colorCount[oldColor]--;
                    if(colorCount[oldColor] == 0){
                        colorCount.erase(oldColor);
                    }
                }
                indexToColor[index] = color;
                colorCount[color]++;
                result.push_back(colorCount.size());
            }
            return result;
        }
};


int main(){

    Solution s;
    // test case 1
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};
    vector<int> result = s.queryResults(4, queries);
    vector<int>output = {1,2,2,3};
    // check if the result is correct
    for(int i = 0; i< result.size(); i++){
        if(result[i] != output[i]){
            cout << "Test failed" << endl;
            return 1;
        }
    }
    cout << "Test passed 1" << endl;

    // test case 2
    queries = {{0,1},{1,2},{2,2},{3,4},{4,5}};
    result = s.queryResults(5, queries);
    output = {1,2,2,3,4};

    for(int i = 0; i< result.size(); i++){
        if(result[i] != output[i]){
            cout << "Test failed" << endl;
            return 1;
        }
    }
    cout << "Test passed 2" << endl;

    cout << endl;

    return 0;
}