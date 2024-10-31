#include<iostream>
using namespace std;

// Brute force solution
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int>answer(temperatures.size(),0);

//         for(int i =0 ; i < temperatures.size();i++){
//             int count=0;
//             int j=i+1;
//             for (;j<temperatures.size();j++){
//                 if (temperatures[i] < temperatures[j] ){
//                     count++;
//                     break;
//                 }
//                 count++;
//             }
//             if (j!=temperatures.size()){
//                 answer[i]=count;
//             } 
//         }
//         return answer;

//     }
// };


// Optimized solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>answer(temperatures.size(),0);
        stack<int>st;
        for ( int i = 0 ; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > st.top()){
                int index = st.top();
                st.pop();
                answer[index] = i - index;  // push index of the temperature
            }
            st.push(i); 
        }
        return answer;
    }
};

int main(){
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> answer = s.dailyTemperatures(temperatures);
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}