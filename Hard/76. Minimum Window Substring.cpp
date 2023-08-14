class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if (n < m)
            return "";
        int cnt = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        unordered_map<char, int> mp;
        for (char c : t)
            mp[c]++;
        for (int i = 0, j = 0; i < n; i++)
        {
            if (--mp[s[i]] >= 0)
                cnt++;
            while (cnt == m)
            {
                if (minLen > i - j + 1)
                {
                    minLen = i - j + 1;
                    minStart = j;
                }
                if (++mp[s[j]] > 0)
                    cnt--;
                j++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};