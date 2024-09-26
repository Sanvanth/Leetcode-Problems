class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Helper function to construct BST recursively
        return helper(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* helper(const vector<int>& nums, int left, int right) {
        // Base case: when the left index exceeds the right index
        if (left > right) {
            return nullptr;
        }
        
        // Choose the middle element as the root
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        
        return root;
    }
};

