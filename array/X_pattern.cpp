#include<bits/stdc++.h>
using namespace std;

int main(){
    string input ="PROGRAM";
    // cin>>input;
    // P R O G R A M    , length = 7 
    /*
    0 1 2 3 4 5 6
    P _ _ _ _ _ M     : 0 + 6 + 1 = 7
    _ R _ _ _ A _     : 1 + 5 + 1 = 7
    _ _ O _ R _ _
    _ _ _ G _ _ _ 
    _ _ O _ R _ _
    _ R _ _ _ A _
    P _ _ _ _ _ M
    
    */
    for(int row =0;row<input.size();row++){
        for(int col =0;col<input.size();col++){
            if(row == col || row+col ==input.size()-1){
                cout<<input[col];
            }
            else{
                cout<< " ";
            }
        }
        cout<<"\n";
    }


    return 0;
}