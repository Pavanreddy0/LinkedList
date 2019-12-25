 struct ListNode
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *addTwoListHelper(ListNode *head1, ListNode *head2, ListNode *result, int len1, int len2, int &carry)
{
    if(!head1 || !head2)
        return NULL;
    ListNode *temp = NULL;
    int sum = 0;
    if(len1 > len2)
    {
        result = addTwoListHelper(head1->next, head2, result, len1 -1, len2, carry);
        sum = head1->val + carry;
    }
    else
    {
        result = addTwoListHelper(head1->next, head2->next, result, len1 -1, len2 - 1, carry);
        sum = head1->val  + head2->val + carry;
    }
    carry = sum / 10;
    sum %= 10;
    temp = new ListNode(sum);
    if(!result)
        result = temp;
    else
    {
        temp->next = result;
        result = temp;
    }
    return result;
}

ListNode *addTwoLists(ListNode *head1, ListNode *head2)
{
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    ListNode *temp;
    int len1 = 0, len2 = 0,carry = 0;
    temp = head1;
    while(temp)
    {
        len1 += 1;
        temp = temp->next;
    }
    temp = head2;
    while(temp)
    {
        len2 += 1;
        temp = temp->next;
    }
    if(len1 < len2)
    {
        swap(head1, head2);
        swap(len1,len2);
    }
    ListNode *result = NULL;
    result = addTwoListHelper(head1, head2, result, len1, len2, carry);
    if(carry > 0)
    {
        temp = new ListNode(carry);
        temp->next = result;
        result = temp;
    }
    return result;
}
