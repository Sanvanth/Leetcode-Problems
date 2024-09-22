function TreeNode(val, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
}

var generateTrees = function(n) {
    if (n === 0) return [];

    // Helper function to generate trees with values from start to end
    const buildTrees = (start, end) => {
        let allTrees = [];
        if (start > end) {
            allTrees.push(null);
            return allTrees;
        }
        
        // Loop over possible root values
        for (let i = start; i <= end; i++) {
            // Recursively get all possible left and right subtrees
            let leftTrees = buildTrees(start, i - 1);
            let rightTrees = buildTrees(i + 1, end);

            // Combine each left and right tree with the current root i
            for (let left of leftTrees) {
                for (let right of rightTrees) {
                    let currentTree = new TreeNode(i);
                    currentTree.left = left;
                    currentTree.right = right;
                    allTrees.push(currentTree);
                }
            }
        }
        
        return allTrees;
    };

    return buildTrees(1, n);
};
