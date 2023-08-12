class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        std::vector<int> res(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int sum = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        std::string ans;
        for (int i = 0; i < res.size(); ++i)
        {
            if (i == 0 && res[i] == 0)
                continue;
            ans += res[i] + '0';
        }
        return ans;
    }
};