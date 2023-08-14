class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;   
    }

    int maxPathSum(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
            return 0;
        int left = maxPathSum(root->left, maxSum);
        int right = maxPathSum(root->right, maxSum);
        int maxChild = max(max(left, right) + root->val, root->val);
        int maxRoot = max(maxChild, left + right + root->val);
        maxSum = max(maxSum, maxRoot);
        return maxChild;
    }
};