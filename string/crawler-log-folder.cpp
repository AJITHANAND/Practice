class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count =0;
        for (auto i : logs){
            if (i == "../"){
                count = max(0,count-1);
            }
            else if (i !="./"){
                count ++;
            }
        }
        return count;
    }
};
