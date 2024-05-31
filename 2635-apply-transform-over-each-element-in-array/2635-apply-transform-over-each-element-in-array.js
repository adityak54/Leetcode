/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const transformedArray = [];
    for(var i=0; i<arr.length; i++){
        transformedArray[i] = fn(arr[i],i);
    }
    return transformedArray;
};