class Solution
{
public:
    string convert(string s, int num_rows)
    {
        if (num_rows > s.size())
        {
            return s;
        }

        if (num_rows == 1)
        {
            return s;
        }
        vector<string> rows(min(num_rows, static_cast<int>(s.size())));
        int cur_row = 0;
        bool going_down = false;
        for (char c : s)
        {
            rows[cur_row] += c;
            if (cur_row == 0 || cur_row == num_rows - 1)
            {
                going_down = !going_down;
            }
            cur_row += going_down ? 1 : -1;
        }
        string ret(s.size(), ' ');
        int index = 0;
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < rows[i].size(); j++)
            {
                ret[index++] = rows[i][j];
            }
        }
        return ret;
    }
};