class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (words.empty())
            return res;
        int n = s.size(), cnt = words.size(), len = words[0].size();
        unordered_map<string, int> m1;
        for (auto &a : words)
            ++m1[a];
        for (int i = 0; i < len; ++i)
        {
            unordered_map<string, int> m2;
            int left = i, count = 0;
            for (int j = i; j <= n - len; j += len)
            {
                string t = s.substr(j, len);
                if (m1.count(t))
                {
                    ++m2[t];
                    if (m2[t] <= m1[t])
                        ++count;
                    else
                    {
                        while (m2[t] > m1[t])
                        {
                            string t1 = s.substr(left, len);
                            --m2[t1];
                            if (m2[t1] < m1[t1])
                                --count;
                            left += len;
                        }
                    }
                    if (count == cnt)
                    {
                        res.push_back(left);
                        --m2[s.substr(left, len)];
                        --count;
                        left += len;
                    }
                }
                else
                {
                    m2.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return res;
    }
};