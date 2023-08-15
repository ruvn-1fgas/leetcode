class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less = new ListNode(0);
        ListNode *greater = new ListNode(0);
        ListNode *lessHead = less;
        ListNode *greaterHead = greater;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                less->next = head;
                less = less->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        greater->next = nullptr;
        less->next = greaterHead->next;
        return lessHead->next;
    }
};