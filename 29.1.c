struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    
    struct ListNode* temp = head;
    int length = 1;
    
    // Find length
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    
    // Make circular
    temp->next = head;
    
    k = k % length;
    int steps = length - k;
    
    struct ListNode* newTail = head;
    
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }
    
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    
    return newHead;
}
