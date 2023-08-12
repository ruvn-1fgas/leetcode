class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *r = q->next;
        q->next = p;
        p->next = swapPairs(r);
        return q;
    }
};