var partition = function(head, x) {
    // Create two dummy nodes for the two partitions.
    let lessHead = new ListNode(0);
    let greaterHead = new ListNode(0);
    
    // Create two pointers to iterate over the two lists.
    let less = lessHead;
    let greater = greaterHead;
    
    // Traverse the original list.
    while (head !== null) {
        if (head.val < x) {
            less.next = head;  // Add the node to the 'less' list.
            less = less.next;
        } else {
            greater.next = head;  // Add the node to the 'greater' list.
            greater = greater.next;
        }
        head = head.next;
    }
    
    // End the 'greater' list to prevent cycle.
    greater.next = null;
    
    // Link the two lists together.
    less.next = greaterHead.next;
    
    // Return the head of the 'less' list.
    return lessHead.next;
};
