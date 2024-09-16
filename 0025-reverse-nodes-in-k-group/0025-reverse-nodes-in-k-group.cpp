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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Count the nodes, we need at least k nodes to reverse
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If we have k nodes, we proceed with reversing them
        if (count == k) {
            curr = head;  // reset curr to head
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            int i = 0;

            // Reverse k nodes
            while (i < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                i++;
            }

            // After reversing, the head is now the last node in the group, 
            // and we need to connect it to the result of the next recursive call
            head->next = reverseKGroup(curr, k);
            
            // Return prev because it's the new head of the reversed list
            return prev;
        }

        // If we have less than k nodes left, we don't reverse and just return the head
        return head;
    }
};
