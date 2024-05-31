/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const filteredArr = [];
    var index = 0;
    arr.filter((ele)=>{
        if(fn(ele,index)) filteredArr.push(ele);
        index++;
    })
    return filteredArr;
};