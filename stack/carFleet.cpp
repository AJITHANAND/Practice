#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int,float>> cars;
        for(size_t i = 0; i < position.size() ; i ++){
            float time = static_cast<float>((target - position[i] )/ static_cast<float>(speed[i]));
            cars.emplace_back(position[i],time);
        }
        sort(cars.rbegin(),cars.rend(),[](const auto& a, const auto& b){
            return a.first < b.first;
        });
#ifdef DEBUG
        std::cout << "Cars sorted by position (from closest to target to farthest):" << std::endl;
        for(const auto& car: cars){
            std::cout << "Position: " << car.first << ", Time to target: " << car.second << std::endl;
        }
#endif
        std::stack<float>fleetCars;
        for(auto car:cars){
#ifdef DEBUG
            std::cout << "Processing car at position " << car.first << " with time " << car.second << std::endl;
#endif
            if (fleetCars.empty() ||  car.second >  fleetCars.top()){
                fleetCars.push(car.second);
            }
        }

        return fleetCars.size();

    }
};


int main() {
    Solution sol;
    vector<int> position = {6,8};
    vector<int> speed = {3,2};
    int target = 10;
    int result = sol.carFleet(target, position, speed);
    std::cout << "Number of car fleets: " << result << std::endl;
    return 0;
}