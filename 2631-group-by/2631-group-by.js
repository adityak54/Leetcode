/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let ans = {};
    for(let i=0; i<this.length; i++){
        let key = fn(this[i]);
        if(ans.hasOwnProperty(key)){
            ans[key].push(this[i]);
        }else ans[key] = [this[i]];
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */