class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();

        vector<int> left(m, 0);
        vector<int> right(m, m);
        vector<int> height(m, 0);

        int max_area = 0;
        for (int i = 0; i < n; i++)
        {
            int cur_left = 0, cur_right = m;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else
                {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }

            for (int j = m - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else
                {
                    right[j] = m;
                    cur_right = j;
                }
            }

            for (int j = 0; j < m; j++)
            {
                max_area = max(max_area, (right[j] - left[j]) * height[j]);
            }
        }

        return max_area;
    }
};