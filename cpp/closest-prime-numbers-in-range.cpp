#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
    private: 
        bool isPrime(int n){
            if (n == 2) {
                return true;
            }
            if (n % 2 == 0 || n == 1) {
                return false;
            }
            int range = sqrt(n);
            for (int i = 3; i <= range; i += 2) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        }
    public:
        vector<int> closestPrimes(int left, int right) {
            int firstNum = -1;
            int secondNum = -1;
            int diff = INT_MAX;
            std::map<int,std::set<pair<int,int>>> primes;
            for(int i = left; i <= right; i++){
                if(isPrime(i)){
                    if(firstNum == -1){
                        firstNum = i;
                    } else if(secondNum == -1){
                        secondNum = i;
                        diff = secondNum - firstNum;
                        primes[diff].insert({firstNum, secondNum});
                        if (diff == 1){
                            return vector<int>{firstNum, secondNum};
                        }
                    } else {
                        if(i - secondNum < diff){
                            firstNum = secondNum;
                            secondNum = i;
                            diff = secondNum - firstNum;
                            primes[diff].insert({firstNum, secondNum});
                        } else {
                            firstNum = secondNum;
                            secondNum = i;
                        }
                    }
                }
            }
            if (diff == INT_MAX){
                return vector<int>{-1,-1};
            }
            return vector<int>{primes[diff].begin()->first, primes[diff].begin()->second};
        }
    };


int main() {
    Solution sol;
    vector<int> res = sol.closestPrimes(10, 19);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}