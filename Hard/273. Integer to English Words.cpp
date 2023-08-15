class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        string res = "";
        vector<string> v = {"", "Thousand", "Million", "Billion"};
        int i = 0;
        while (num > 0)
        {
            if (num % 1000 != 0)
                res = helper(num % 1000) + v[i] + " " + res;
            num /= 1000;
            i++;
        }
        while (res.back() == ' ')
            res.pop_back();
        return res;
    }

    string helper(int num)
    {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> v2 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                             "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v3 = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                             "Sixty", "Seventy", "Eighty", "Ninety"};
        string res = "";
        int a = num / 100;
        int b = num % 100;
        int c = num % 10;
        if (a > 0)
            res = v1[a] + " Hundred ";
        if (b >= 10 && b < 20)
            res += v2[b - 10] + " ";
        else
        {
            if (b >= 20)
                res += v3[b / 10] + " ";
            if (c > 0)
                res += v1[c] + " ";
        }
        return res;
    }
};