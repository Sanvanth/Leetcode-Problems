class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes to start the two lists
        ListNode* before_head = new ListNode(0); // Nodes less than x
        ListNode* after_head = new ListNode(0);  // Nodes greater than or equal to x

        // Pointers to the current node in each list
        ListNode* before = before_head;
        ListNode* after = after_head;

        // Traverse the original list
        while (head != nullptr) {
            if (head->val < x) {
                // Add to the 'before' list
                before->next = head;
                before = before->next;
            } else {
                // Add to the 'after' list
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        // Link the two lists together
        after->next = nullptr;  // End the after list
        before->next = after_head->next;  // Append after list to before list

        // Return the head of the modified list
        return before_head->next;
    }
};
