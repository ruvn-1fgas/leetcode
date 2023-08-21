class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &dictionary)
    {
        n = s.size();
        for (auto &word : dictionary)
            dict.insert(word);
        dfs(s, 0);
        return res;
    }

private:
    vector<string> res;
    vector<string> path;
    unordered_set<string> dict;
    int n;
    void dfs(string s, int start)
    {
        if (start == n)
        {
            string tmp;
            for (int i = 0; i < path.size(); i++)
            {
                tmp += path[i];
                if (i != path.size() - 1)
                    tmp += " ";
            }
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < n; i++)
        {
            string tmp = s.substr(start, i - start + 1);
            if (dict.find(tmp) != dict.end())
            {
                path.push_back(tmp);
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }
};