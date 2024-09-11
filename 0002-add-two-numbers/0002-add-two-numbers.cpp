/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // Create a dummy head for the result list
        ListNode* current = dummyHead;  // Pointer to traverse and build the new list
        int carry = 0;  // Initialize carry to 0

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from l1 and l2, if nodes exist; otherwise, use 0
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate the sum of values plus the carry
            int sum = val1 + val2 + carry;
            
            // Update carry (sum / 10)
            carry = sum / 10;
            
            // The new node's value is the sum modulo 10
            current->next = new ListNode(sum % 10);
            
            // Move the current pointer
            current = current->next;
            
            // Move to the next nodes in l1 and l2, if they exist
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the head of the new list (skipping the dummy node)
        return dummyHead->next;
    }
};
