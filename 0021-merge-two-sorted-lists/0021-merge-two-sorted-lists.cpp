class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the start of the merged list
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        
        // Iterate as long as both lists have elements
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;  // Attach list1 node
                list1 = list1->next;    // Move to the next node in list1
            } else {
                current->next = list2;  // Attach list2 node
                list2 = list2->next;    // Move to the next node in list2
            }
            current = current->next;    // Move the current pointer
        }
        
        // If any list still has remaining elements, attach it to the merged list
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        // Return the merged list, starting from the next of the dummy node
        return dummy->next;
    }
};
