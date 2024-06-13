/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    arr.sort(function(x,y){
        return fn(x)-fn(y)
//         positive -> x will come after y
//         negative -> y will come after x
    })
    return arr;
};