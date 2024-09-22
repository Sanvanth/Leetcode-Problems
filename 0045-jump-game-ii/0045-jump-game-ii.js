var jump = function(nums) {
    let jumps = 0;     // To store the minimum number of jumps
    let maxReach = 0;  // The furthest index we can reach so far
    let end = 0;       // The current end of the range of jumps
    
    for (let i = 0; i < nums.length - 1; i++) {
        // Update the maximum reach we can get to
        maxReach = Math.max(maxReach, i + nums[i]);
        
        // If we reach the end of the current range, we need to jump
        if (i === end) {
            jumps++;
            end = maxReach; // Update the range to the furthest point we can now reach
        }
        
        // Early exit if we can already reach the last index
        if (end >= nums.length - 1) {
            break;
        }
    }
    
    return jumps;
};
