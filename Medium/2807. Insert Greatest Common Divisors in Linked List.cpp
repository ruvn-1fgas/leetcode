class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *node = head;
        while (node != nullptr && node->next != nullptr) {
            int gcd = std::gcd(node->val, node->next->val);
            ListNode *newNode = new ListNode(gcd);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }
        return head;
    }
};