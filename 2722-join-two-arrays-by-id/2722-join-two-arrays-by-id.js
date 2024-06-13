/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let map = new Map();
    arr1.forEach((element)=>map.set(element.id, element));
    arr2.forEach((element)=>{
        if(map.has(element.id)){
            for(key in element){
                map.get(element.id)[key] = element[key];
            }
        }else{
            map.set(element.id,element);
        }
    });
    let ans = Array.from(map.values());
    ans.sort((x,y)=>x.id-y.id);
    return ans;
};