class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;
        int len = 1;

        while (temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }

        temp->next = head;

        k = k % len;
        k = len - k;

        while (k--)
        {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};