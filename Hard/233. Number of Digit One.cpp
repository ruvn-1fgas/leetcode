class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        long long base = 1;
        while (n >= base) {
            int digit = (n / base) % 10;
            int left = n / (base * 10);
            int right = n % base;
            if (digit == 0) {
                count += left * base;
            } else if (digit == 1) {
                count += left * base + right + 1;
            } else {
                count += (left + 1) * base;
            }
            base *= 10;
        }
        return count;
    }
};