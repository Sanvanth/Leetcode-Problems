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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: List is empty or has only one node
        }

        // Find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        ListNode* rightHalf = slow->next;
        slow->next = nullptr;

        // Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        // Merge the sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1); // Dummy node for easier merging
        ListNode* current = dummy;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        // Append any remaining elements from either list
        current->next = left ? left : right;

        return dummy->next; // Return the head of the merged list
    }
};