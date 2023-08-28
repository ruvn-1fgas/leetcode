class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        return sortedArrayToBST(arr);
    }

    TreeNode *sortedArrayToBST(vector<int> a)
    {
        if (a.size() == 0)
            return NULL;
        int mid = a.size() / 2;
        TreeNode *root = new TreeNode(a[mid]);
        vector<int> left(a.begin(), a.begin() + mid);
        vector<int> right(a.begin() + mid + 1, a.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};