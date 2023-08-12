class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        for (int i = 0; i < n; i++)
        {
            curr = curr->next;
        }
        while (curr != nullptr)
        {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};