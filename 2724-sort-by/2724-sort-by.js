/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    arr.sort(function(x,y){
        return fn(x)-fn(y)
    })
    return arr;
};