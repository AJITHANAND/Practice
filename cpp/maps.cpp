#include <iostream>
#include <map>

template<typename K, typename V>
bool areMapsEqual(const std::map<K, V>& map1, const std::map<K, V>& map2) {
    // Check if the sizes of the maps are equal
    if (map1.size() != map2.size()) {
        return false;
    }

    // Iterate over the elements of map1
    for (const auto& pair : map1) {
        const K& key = pair.first;
        const V& value = pair.second;

        // Check if the key exists in map2
        auto it = map2.find(key);
        if (it == map2.end()) {
            return false;
        }

        // Check if the corresponding value is the same
        if (it->second != value) {
            return false;
        }
    }

    return true;
}

int main() {
    std::map<int, std::string> map1 = {{1, "one"}, {2, "two1"}, {3, "three"}};
    std::map<int, std::string> map2 = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::map<int, std::string> map3 = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};

    bool equal1 = areMapsEqual(map1, map2);
    bool equal2 = areMapsEqual(map1, map3);

    std::cout << "Are map1 and map2 equal? " << (equal1 ? "Yes" : "No") << std::endl;
    std::cout << "Are map1 and map3 equal? " << (equal2 ? "Yes" : "No") << std::endl;

    return 0;
}
