class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            bool prev = dp[0];
            dp[0] = false;
            for (int j = 1; j <= n; j++) {
                bool temp = dp[j];
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[j] = prev;
                } else if (p[j - 1] == '*') {
                    dp[j] = dp[j - 1] || dp[j];
                } else {
                    dp[j] = false;
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};