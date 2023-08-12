class Solution
{
public:
    int reverse(int x)
    {
        if (x == INT_MIN)
        {
            return 0;
        }
        int sign = x < 0 ? -1 : 1;
        x *= sign;
        long long result = 0;
        while (x > 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }

        if (result > INT_MAX)
        {
            return 0;
        }
        return result * sign;
    }
};