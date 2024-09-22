var removeDuplicates = function(nums) {
    let j = 0;  // pointer to track the position of the next unique element
    for (let i = 0; i < nums.length; i++) {
        // Check if the current element should be placed in the first part
        // Only allow placing the element if it's the first or second occurrence
        if (j < 2 || nums[i] != nums[j - 2]) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;  // j will be the length of the array with duplicates removed
};
