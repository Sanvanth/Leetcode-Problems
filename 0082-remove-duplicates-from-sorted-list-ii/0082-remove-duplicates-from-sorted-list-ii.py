# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # Create a dummy node to handle edge cases where the head itself is a duplicate
        dummy = ListNode(0)
        dummy.next = head
        
        # Initialize prev as dummy and current as head
        prev = dummy
        current = head
        
        while current:
            # Check if the current node is a duplicate
            if current.next and current.val == current.next.val:
                # Skip all nodes with the same value
                while current.next and current.val == current.next.val:
                    current = current.next
                # After skipping, link prev to current's next (skip duplicates)
                prev.next = current.next
            else:
                # No duplicates, move prev to current
                prev = prev.next
            # Move current to the next node
            current = current.next
        
        # Return the updated list, skipping dummy node
        return dummy.next
