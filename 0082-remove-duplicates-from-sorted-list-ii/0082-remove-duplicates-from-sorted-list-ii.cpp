class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to handle edge cases (like head being a duplicate)
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy; // Pointer to the node before the current sequence
        
        while (head) {
            // If there's a duplicate (i.e., head and head->next have the same value)
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Move prev's next to the node after the last duplicate
                prev->next = head->next;
            } else {
                // If no duplicate, move prev to the next node
                prev = prev->next;
            }
            // Move head forward
            head = head->next;
        }
        
        // Return the updated list (skipping the dummy node)
        return dummy->next;
    }
};
