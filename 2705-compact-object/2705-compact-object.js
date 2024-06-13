/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if(Array.isArray(obj)){
        return obj.map((element)=>compactObject(element))
                  .filter((element)=>Boolean(element));
    }
    if(obj!==null && typeof obj==="object"){
        let ans = {};
        for(const key in obj){
            obj[key] = compactObject(obj[key]);
            if(Boolean(obj[key])) ans[key] = obj[key];
        }
        return ans;
    }
    return obj
};