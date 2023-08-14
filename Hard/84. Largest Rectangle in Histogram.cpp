class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;
        int i = 0;
        while (i < n)
        {
            if (st.empty() || heights[st.top()] <= heights[i])
            {
                st.push(i++);
            }
            else
            {
                int top = st.top();
                st.pop();
                int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
                max_area = max(max_area, area);
            }
        }
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};