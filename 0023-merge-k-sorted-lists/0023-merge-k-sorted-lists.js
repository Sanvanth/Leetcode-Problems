class MinHeap {
    constructor() {
        this.heap = [];
    }
    
    // Add a new node to the heap
    push(node) {
        this.heap.push(node);
        this.bubbleUp(this.heap.length - 1);
    }
    
    // Extract the smallest node from the heap
    pop() {
        if (this.heap.length === 1) return this.heap.pop();
        
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        
        return min;
    }
    
    // Bubble up to maintain the heap property
    bubbleUp(index) {
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            if (this.heap[index].val < this.heap[parentIndex].val) {
                [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
                index = parentIndex;
            } else {
                break;
            }
        }
    }
    
    // Bubble down to maintain the heap property
    bubbleDown(index) {
        const length = this.heap.length;
        while (true) {
            let smallest = index;
            const leftChild = 2 * index + 1;
            const rightChild = 2 * index + 2;
            
            if (leftChild < length && this.heap[leftChild].val < this.heap[smallest].val) {
                smallest = leftChild;
            }
            
            if (rightChild < length && this.heap[rightChild].val < this.heap[smallest].val) {
                smallest = rightChild;
            }
            
            if (smallest !== index) {
                [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
                index = smallest;
            } else {
                break;
            }
        }
    }
    
    // Check if the heap is empty
    isEmpty() {
        return this.heap.length === 0;
    }
}

// Definition for singly-linked list node
function ListNode(val, next = null) {
    this.val = val;
    this.next = next;
}

var mergeKLists = function(lists) {
    if (!lists || lists.length === 0) return null;
    
    const heap = new MinHeap();
    
    // Add the head of each linked list to the heap
    for (let list of lists) {
        if (list !== null) {
            heap.push(list);
        }
    }
    
    let dummy = new ListNode(0);
    let current = dummy;
    
    // Merge the lists
    while (!heap.isEmpty()) {
        let node = heap.pop();
        current.next = node;
        current = current.next;
        
        // If there is a next node in the current list, add it to the heap
        if (node.next !== null) {
            heap.push(node.next);
        }
    }
    
    return dummy.next;
};
