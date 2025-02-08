#include <iostream> 
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;



class NumberContainers {
    private:
        std::unordered_map<int,std::set<int>> numberToIndex;
        std::unordered_map<int,int> indexToNumber;
    public:
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if(indexToNumber.find(index) != indexToNumber.end()){
                numberToIndex[indexToNumber[index]].erase(index);
                
            }
            indexToNumber[index] = number;
            numberToIndex[number].insert(index);
        }
        
        int find(int number) {
            if (!numberToIndex[number].empty()) {
                return *numberToIndex[number].begin();
            }
            return -1; 
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */

int main(){



    return 0;
}