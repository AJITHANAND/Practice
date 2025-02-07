#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// class Solution {
//     public:
//         vector<int> queryResults(int limit, vector<vector<int>>& queries) {
//             std::unordered_map<int, int> indexToColor;
//             std::unordered_map<int, int> colorCount;
//             vector<int> result;
//             for(int i =0; i< queries.size(); i++){
//                 int color = queries[i][1];
//                 int index = queries[i][0];
                
//                 if(indexToColor.find(index) != indexToColor.end()){
//                   int oldColor = indexToColor[index];
//                   colorCount[oldColor]--;
//                     if(colorCount[oldColor] == 0){
//                         colorCount.erase(oldColor);
//                     }
//                 }
//                 indexToColor[index] = color;
//                 colorCount[color]++;
//                 result.push_back(colorCount.size());
//             }
//             return result;
//         }
// };


// optimized
class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            auto ball_to_color = unordered_map<int, int>{};
            auto color_count = unordered_map<int, int>{};
            auto result = vector<int>{};
            int num_colors = 0;
            result.reserve(queries.size());
            for(const auto& query : queries){
                auto [ball, color] = make_pair(query[0], query[1]);
                auto &old_color = ball_to_color[ball];
                if(old_color){
                    if(--color_count[old_color] == 0) --num_colors;
                }
                ball_to_color[ball] = color;
                if(++color_count[color] == 1) ++num_colors;
                result.push_back(num_colors);
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