
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

private:
    bool solve(vector<vector<char>> &board)
    {
        int row = -1, col = -1;
        bool isEmpty = true;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    row = i;
                    col = j;
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty)
                break;
        }
        if (isEmpty)
            return true; 
        for (char c = '1'; c <= '9'; c++)
        {
            if (isValid(board, row, col, c))
            {
                board[row][col] = c;
                if (solve(board))
                    return true;      
                board[row][col] = '.'; 
            }
        }
        return false; 
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.' && board[i][col] == c)
                return false;
            if (board[row][i] != '.' && board[row][i] == c)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};