class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        while (curr != NULL)
        {
            bool is_unique = true;
            while (curr->next != NULL && curr->val == curr->next->val)
            {
                is_unique = false;
                curr = curr->next;
            }
            if (is_unique)
            {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return dummy->next;
    }
};