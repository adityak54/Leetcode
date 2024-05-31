/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const transformedArray = [];
    var i = 0;
    arr.map((ele)=>{
        transformedArray.push(fn(ele,i));
        i++;
    })
    return transformedArray;
};