class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Step 2: Find the next larger element to swap with
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap elements at i and j
            swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the sequence from i+1 to the end
        reverse(nums.begin() + i + 1, nums.end());
    }
};
