class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        if (k >= n / 2)
        {
            int maxPro = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                    maxPro += prices[i] - prices[i - 1];
            }
            return maxPro;
        }
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++)
        {
            int maxTemp = -prices[0];
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxTemp);
                maxTemp = max(maxTemp, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};