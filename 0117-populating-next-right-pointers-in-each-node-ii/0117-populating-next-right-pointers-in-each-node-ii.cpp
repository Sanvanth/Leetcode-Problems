/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root; // If the root is null, return null
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // Get the size of the current level

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                // Connect the node's next pointer to the next node in the queue
                node->next = (i < size - 1) ? q.front() : NULL;

                // Enqueue the node's children if they exist
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};