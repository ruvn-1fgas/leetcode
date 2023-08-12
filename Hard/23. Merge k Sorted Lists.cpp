class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;

        ListNode *result = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *result = new ListNode();
        ListNode *current = result;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1 != nullptr)
        {
            current->next = l1;
        }
        if (l2 != nullptr)
        {
            current->next = l2;
        }

        return result->next;
    }
};