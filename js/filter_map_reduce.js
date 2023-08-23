let arr = [1,2,3,4,5,6,7,8,9,10];


let result = arr.filter((val)=>val%2 ==0);
console.log(result);

result = arr.map((val)=> val%2==0 ? val : null);
console.log(result);

result = arr.reduce((acc,val)=>acc + val);
console.log(result);