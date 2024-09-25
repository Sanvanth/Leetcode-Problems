class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result; // To store all unique permutations
        vector<int> currentPermutation; // To build the current permutation
        vector<bool> used(nums.size(), false); // To mark used elements in the current permutation
        
        // Sort the numbers to facilitate skipping duplicates
        sort(nums.begin(), nums.end());
        
        // Start the backtracking process
        backtrack(nums, used, currentPermutation, result);
        
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& currentPermutation, vector<vector<int>>& result) {
        // If the current permutation is complete, add it to the result
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }
        
        // Iterate over the numbers to build permutations
        for (int i = 0; i < nums.size(); ++i) {
            // Skip the used elements
            if (used[i]) {
                continue;
            }
            
            // Skip duplicates: If nums[i] is the same as nums[i - 1] and the previous one hasn't been used,
            // it means this number has been considered in the current level already.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            
            // Include nums[i] in the current permutation
            used[i] = true;
            currentPermutation.push_back(nums[i]);
            
            // Recursively build the next level of the permutation
            backtrack(nums, used, currentPermutation, result);
            
            // Backtrack: remove the last element and mark it as unused
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
};
