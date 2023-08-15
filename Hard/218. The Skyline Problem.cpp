class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> res;
        vector<pair<int, int>> heights;
        multiset<int> s;
        int pre = 0, cur = 0;
        for (auto &a : buildings)
        {
            heights.push_back({a[0], -a[2]});
            heights.push_back({a[1], a[2]});
        }
        sort(heights.begin(), heights.end());
        s.insert(0);
        for (auto &a : heights)
        {
            if (a.second < 0)
                s.insert(-a.second);
            else
                s.erase(s.find(a.second));
            cur = *s.rbegin();
            if (cur != pre)
            {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};