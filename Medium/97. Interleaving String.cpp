class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n1; ++i)
        {
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = true;
            else
                break;
        }
        for (int j = 1; j <= n2; ++j)
        {
            if (s2[j - 1] == s3[j - 1])
                dp[0][j] = true;
            else
                break;
        }
        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                if ((s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]))
                    dp[i][j] = true;
            }
        }
        return dp[n1][n2];   
    }
};