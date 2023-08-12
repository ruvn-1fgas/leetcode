class SubrectangleQueries
{
public:
    SubrectangleQueries(vector<vector<int>>& rectangle)
        : rectangle(rectangle)
    {
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        updates.emplace_back(row1, col1, row2, col2, newValue);
    }

    int getValue(int row, int col)
    {
        for (auto it = updates.rbegin(); it != updates.rend(); ++it)
        {
            int row1, col1, row2, col2, value;
            std::tie(row1, col1, row2, col2, value) = *it;
            if (row >= row1 && row <= row2 && col >= col1 && col <= col2)
            {
                return value;
            }
        }
        return rectangle[row][col];
    }

private:
    vector<vector<int>>& rectangle;
    vector<tuple<int, int, int, int, int>> updates;
};