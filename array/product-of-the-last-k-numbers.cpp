#include <iostream>
using namespace std;


// brute force
// class ProductOfNumbers {
//     std::vector<int>nums;
// public:
//     ProductOfNumbers() {
        
//     }
    
//     void add(int num) {
//         nums.push_back(num);
//     }
    
//     int getProduct(int k) {
//         int sum=1;
//         for(int i = 0 ;i<k && 0<=nums.size()-1;i++){
//             sum*=nums[nums.size()-1-i];
//         }
//         return sum;
//     }
// };

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


 // optimized

 class ProductOfNumbers {
    vector<long long> prefix;
public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        if(k >= prefix.size())
            return 0;
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};

int main(){
    ProductOfNumbers* obj = new ProductOfNumbers();
    // ["ProductOfNumbers","add","getProduct","getProduct","getProduct","add","add","add"]
    // [[],[1],[1],[1],[1],[7],[6],[7]]
    obj->add(1);
    cout<<obj->getProduct(1)<<endl;
    cout<<obj->getProduct(1)<<endl;
    cout<<obj->getProduct(1)<<endl;
    obj->add(7);
    obj->add(6);
    obj->add(7);   
    return 0;
}