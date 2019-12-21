 struct ListNode
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 ListNode* reverse(ListNode* A)
{
    ListNode *temp, *prev, *next;
    temp = A;
    prev = NULL; next = NULL;
    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    A = prev;
    return A;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(!A || !A->next)
        return A;
    ListNode *first, *last, *next;
    first = A;
    last = NULL;
    int i;
    
//    if reverese from begining
    if(B == 1)
    {
        last = A;
        for(i = 1; i < C; i++)
        if(last)
            last = last->next;
        next = last->next;
        last->next = NULL;
        A = reverse(A);
        last = A;
        while(last->next)
            last = last->next;
        last->next = next;
        return A;
    }

//    If reverse is not from begining
//    Finding element before statrt position
    for(i = 1;i + 1 < B; i++)
        if(first)
            first = first->next;
    
//    Finding the lelement at the end position
    last = first->next;
    for(i = 1; i <= C - B; i++)
        if(last)
            last = last->next;
//    temp = NULL;
//    Storing the next element of end node
    next = last->next;
//    Assigning the next node of end to NULL, so we can do a normal reverse from the start index Node
    last->next = NULL;
    first->next = reverse(first->next);
    while(first->next)
        first = first->next;
//    After the reversal we can assign the last position Node next to the original next Node
    first->next = next;
    return A;
}
