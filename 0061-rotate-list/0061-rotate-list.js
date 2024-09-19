var rotateRight = function(head, k) {
    if (!head || !head.next || k === 0) {
        return head;
    }
    
    // Step 1: Find the length of the linked list
    let length = 1;
    let tail = head;
    
    // Traverse to the end of the list to find the tail and calculate the length
    while (tail.next) {
        tail = tail.next;
        length++;
    }
    
    // Step 2: Link the tail to the head to form a circular linked list
    tail.next = head;
    
    // Step 3: Find the new tail (the node before the new head) after the rotation
    k = k % length;  // In case k is greater than length
    let stepsToNewTail = length - k;
    let newTail = head;
    
    // Move to the new tail
    for (let i = 1; i < stepsToNewTail; i++) {
        newTail = newTail.next;
    }
    
    // Step 4: Break the circular linked list and return the new head
    let newHead = newTail.next;
    newTail.next = null;
    
    return newHead;
};
