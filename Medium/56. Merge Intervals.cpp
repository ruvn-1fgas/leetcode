class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int i = 0;
        while (i < n)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (i < n - 1 && end >= intervals[i + 1][0])
            {
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            ans.push_back({start, end});
            i++;
        }
        return ans;
    }
};