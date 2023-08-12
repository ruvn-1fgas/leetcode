class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string s;
        dfs(res, s, n, n);
        return res;
    }

    void dfs(vector<string> &res, string s, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(s);
            return;
        }
        if (left > 0)
        {
            dfs(res, s + "(", left - 1, right);
        }
        if (right > left)
        {
            dfs(res, s + ")", left, right - 1);
        }
    }
};