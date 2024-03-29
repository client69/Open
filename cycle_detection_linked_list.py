#if cycle found it will return 1
#else it will return 0

def has_cycle(head):
    
    if head is None:
        return 0
    
    if head.next is None:
        return 0
    
    slow = head
    fast = head
    
    while fast != None and slow != None:
        slow = slow.next
        if fast.next is not None:
            fast = fast.next.next
        else:
            fast = fast.next
        
        if slow == fast :
            return 1
    

    return 0
