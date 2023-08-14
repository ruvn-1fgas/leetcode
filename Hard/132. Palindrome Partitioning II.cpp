class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> cut(n, 0);
        for (int i = 0; i < n; ++i) {
            int min_cut = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 1 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    min_cut = j == 0 ? 0 : min(min_cut, cut[j - 1] + 1);
                }
            }
            cut[i] = min_cut;
        }
        return cut[n - 1];
    }
};