#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define endl "\n"

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
    bool rowValid(vector<char>& board,char val ){
        bool one=false;
        for(char i : board){
            if(val == i){
                if(one){
                    return false;

                }else{
                    one=true;
                }
            }
        }
        return true;
    }
    bool colValid(vector<vector<char>>& board ,int col ,char val){
        bool one=false;
        for (int i =0;i<9;i++){
            if (board[i][col] == val){
                if(one){
                    return false;
                }else{
                    one=true;
                }
            }
        }
        return true;
    }
    bool miniBox(vector<vector<char>>& board ,int row ,int col ,char val){
        int boxCol = (col / 3)*3;
        int boxRow = (row / 3)*3;
        bool one = false;
        for(int i =0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(board[boxRow+i][boxCol+j] == val ){
                    if(one){
                        return false;
                    }else{
                        one=true;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i =0;i<9;i++){
            for(int j =0 ;j<9;j++){
                if (board[i][j] == '.') continue;
                if((!rowValid(board[i],board[i][j])) || (!colValid(board,j,board[i][j])) || (!miniBox(board,i,j,board[i][j])) ){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    vector<vector<char>> board
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, { '.', '.', '.', '.', '8', '.', '.', '7', '9' },
    };
    Solution st;
    cout<<(st.isValidSudoku(board)?"Is valid":"Not Valid");

    return 0;
}