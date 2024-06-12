var TimeLimitedCache = function() {
    this.dp = {};
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    if (this.dp.hasOwnProperty(key)) {
        this.dp[key]["value"] = value;
        clearTimeout(this.dp[key]["timeoutId"]);
        this.dp[key]["timeoutId"] = setTimeout(() => {
        delete this.dp[key];
        },duration);
        return true;
    } else {
        this.dp[key] = {
            value: value
        };
    }
    this.dp[key]["timeoutId"] = setTimeout(() => {
        delete this.dp[key];
    }, duration);
    return false;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    return key in this.dp ? this.dp[key]["value"] : -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let cnt = 0;
    for(key in this.dp){
        if(this.dp[key]["value"]!==-1) cnt++;
    }
    return cnt;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */