class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> currentSubset;   // To store the current subset
        generateSubsets(0, nums, currentSubset, result);
        return result;
    }
    
    void generateSubsets(int index, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Add the current subset to the result (a copy of the currentSubset)
        result.push_back(currentSubset);
        
        // Explore all further elements
        for (int i = index; i < nums.size(); ++i) {
            // Include nums[i] in the current subset
            currentSubset.push_back(nums[i]);
            
            // Recurse with the next index
            generateSubsets(i + 1, nums, currentSubset, result);
            
            // Backtrack: remove the last element added (nums[i])
            currentSubset.pop_back();
        }
    }
};
