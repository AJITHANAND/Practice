let first = "rat";
let second = "tar";


var isAnagram = function(first, second) {
    let mp = {};
    if (first.length != second.length) return false;
    for (let i = 0; i < first.length; i++) {
        if (mp[first[i]]) {
            mp[first[i]]++;
        } else {
            mp[first[i]] = 1;
        }
    }
    for (let i = 0; i < second.length; i++) {
        if (mp[second[i]]) {
            mp[second[i]]--;
        } else {
            return false;
        }
    }
    for (let i in mp) {
        if (mp[i] != 0) return false;
    }
    return true;
};


console.log(isAnagram(first, second ));