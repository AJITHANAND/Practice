#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// bool isPowerOfTwo(int n){
//     if (n <= 0) return false;
//     if (n == 1) return true;
//     if (n % 2 != 0) return false;
//     return isPowerOfTwo(n/2);
// }


// a power of two in binary form has only one ‘1’ and the rest are '0’s.
// 4 = 0100 // 
// 3 = 0011
// 4 & 3 = 0000

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cout<< (isPowerOfTwo(0) ? "true" : "false") <<endl;
    cout<< (isPowerOfTwo(1) ? "true" : "false") <<endl;
    cout<< (isPowerOfTwo(2) ? "true" : "false") <<endl;
    cout<< (isPowerOfTwo(10) ? "true" : "false") <<endl;
    cout<< (isPowerOfTwo(16) ? "true" : "false") <<endl;
  
  
  
    return 0;
}