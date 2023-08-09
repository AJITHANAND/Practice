var expect  = (val)=>{
    return {
        toBe:(test)=>{
            if(test === val )
                return true;
            throw new Error("Not Equal");
        },
        notToBe : (test)=>{
            if(test!== val)
                return true;
            throw new Error("Equal");
        }
    }
}


expect(5).toBe(5); //  {"value":true}
expect(5).notToBe(5); // {"error":"Equal"}
