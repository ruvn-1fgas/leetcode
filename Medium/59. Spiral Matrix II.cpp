class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int row = 0, col = 0;
        int row_dir = 0, col_dir = 1;

        for (int i = 1; i <= n * n; i++)
        {
            matrix[row][col] = i;

            if (row + row_dir >= n || col + col_dir >= n || row + row_dir < 0 || col + col_dir < 0 || matrix[row + row_dir][col + col_dir] != 0)
            {
                int temp = row_dir;
                row_dir = col_dir;
                col_dir = -temp;
            }

            row += row_dir;
            col += col_dir;
        }

        return matrix;
    }
};