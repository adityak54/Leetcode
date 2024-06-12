/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let dp = {};
    return function(...args) {
        let key = JSON.stringify(args);
        if(key in dp) return dp[key];
        return dp[key] = fn(...args);
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */