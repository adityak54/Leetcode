/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.nums = nums;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    let sum = 0;
    this.nums.map((val)=>sum+=val);
    return sum;
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    let ans = "[";
    ans += this.nums.toString();
    ans += "]";
    return ans;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */