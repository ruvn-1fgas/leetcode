class Solution
{
public:
    int myAtoi(string s)
    {
        trim(s);
        if (s.empty())
        {
            return 0;
        }

        int sign = 1;
        int i = 0;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        long long res = 0;
        for (; i < s.size(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                break;
            }
            res = res * 10 + (s[i] - '0');
            if (res > INT_MAX)
            {
                break;
            }
        }

        res *= sign;

        return res > INT_MAX ? INT_MAX : (res < INT_MIN ? INT_MIN : res);
    }

private:
    void trim(string &s)
    {
        if (s.empty())
        {
            return;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
};