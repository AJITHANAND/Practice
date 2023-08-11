let arr = [2,7,11,15];
let target = 9;

var twoSum = function(arr, target) {
    let seen = {};
    for(let i = 0;i<arr.length;i++){
        if(seen.hasOwnProperty([arr[i]])){
            return [seen[arr[i]],i];
        }
        seen[target-arr[i]] =i;
    }
    return [];
};

console.log(twoSum(arr, target));