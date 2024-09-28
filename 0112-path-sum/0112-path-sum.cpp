class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // If the root is null, there is no path
        if (!root) return false;
        
        // If it's a leaf node (no children), check if the remaining sum equals the node's value
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        // Recursively check the left and right subtrees with the updated target sum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
