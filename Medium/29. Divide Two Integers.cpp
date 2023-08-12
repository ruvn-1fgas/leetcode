class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (dividend == INT_MAX && divisor == 1)
            return INT_MAX;
        if (dividend == INT_MAX && divisor == -1)
            return INT_MIN + 1;
        if (dividend == INT_MIN && divisor == INT_MIN)
            return 1;
        if (divisor == INT_MIN)
            return 0;
        if (dividend == INT_MIN)
        {
            if (divisor > 0)
                return -1 + divide(dividend + divisor, divisor);
            else
                return 1 + divide(dividend - divisor, divisor);
        }
        if (dividend < 0 && divisor < 0)
            return divide(-dividend, -divisor);
        if (dividend < 0)
            return -divide(-dividend, divisor);
        if (divisor < 0)
            return -divide(dividend, -divisor);
        
        int quotient = 0;
        long long a = dividend, b = divisor;
        bool negative = false;
        if (a < 0) {
            a = -a;
            negative = !negative;
        }
        if (b < 0) {
            b = -b;
            negative = !negative;
        }
        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                quotient += (1 << i);
                a -= (b << i);
            }
        }
        return negative ? -quotient : quotient;
    }
};