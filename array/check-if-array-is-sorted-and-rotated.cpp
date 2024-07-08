class Solution {
public:
    bool check(vector<int>& arr) {
        bool first_part =false;
        for (int i = 1 ;i < arr.size() ;i ++){
            if (arr[i-1] > arr[i]){
                if(!first_part){
                    first_part = true;
                }else{
                    return false;
                }
            }
        }
        if (arr[0] >= arr[arr.size()-1] || (!first_part))
            return true;
        return false;
    }
};
