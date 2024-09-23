class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr || root->left == nullptr) {
            return root;
        }

        // Connect the left and right child of the current node
        root->left->next = root->right;

        // Connect the right child of the current node to the left child of the next node
        if (root->next != nullptr) {
            root->right->next = root->next->left;
        }

        // Recursively connect the left and right subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};
