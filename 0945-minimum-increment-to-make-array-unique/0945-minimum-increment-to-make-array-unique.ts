function minIncrementForUnique(nums: number[]): number {
    nums.sort((x,y)=>x-y);
    let ans:number = 0;
    for(let i=0; i<nums.length; i++){
        if(nums[i]<=nums[i-1]){
            ans += nums[i-1]-nums[i]+1;
            nums[i] = nums[i-1]+1;
        }
    }
    return ans;
};