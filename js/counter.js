/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    temp = init;
    return {
        increment :()=>{
            return ++temp;
        },
        reset:()=>{
            temp=init;
            return init;
        },
        decrement:()=>{
            return --temp;
        }
    }
};


const counter = createCounter(5)
console.log(counter.increment());  // 6
console.log(counter.reset());   // 5
console.log(counter.decrement()); // 4
