/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let chunkedArr = [];
    let currChunkedArr = [];
    for(let i=0; i<arr.length; i++){
        currChunkedArr.push(arr[i]);
        if(currChunkedArr.length==size || i===arr.length-1){
            chunkedArr.push(currChunkedArr);
            currChunkedArr = []
        }
    }
    return chunkedArr;
};
