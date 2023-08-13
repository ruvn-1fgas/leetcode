class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);
        k--;
        for (int i = 1; i < n; i++)
        {
            int j = k / factorial(n - i);
            k %= factorial(n - i);
            swap(s[i - 1], s[i - 1 + j]);
            sort(s.begin() + i, s.end());
        }
        return s;
    }

private:
    int factorial(int n)
    {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }
};