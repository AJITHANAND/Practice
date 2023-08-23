const arr  = [1,2,3,4,5,6,7,9,10];


function oddNumbers(arr,callback){
    let odd = arr.filter((val)=>{
        if(callback(val)){
            return val;
        }
    }
    )
    return odd;
}


console.log(oddNumbers(arr,(x)=>x%2==0))