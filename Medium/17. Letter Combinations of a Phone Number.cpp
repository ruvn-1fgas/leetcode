class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
        {
            return res;
        }
        res.reserve(pow(3, digits.size()));
        res.push_back("");
        for (auto digit : digits)
        {
            vector<string> tmp;
            tmp.reserve(res.size() * m[digit - '0'].size());
            for (auto candidate : m[digit - '0'])
            {
                for (auto s : res)
                {
                    tmp.push_back(s + candidate);
                }
            }
            res.swap(tmp);
        }
        return res;
    }

private:
    map<int, vector<string>> m = {
        {2, {"a", "b", "c"}},
        {3, {"d", "e", "f"}},
        {4, {"g", "h", "i"}},
        {5, {"j", "k", "l"}},
        {6, {"m", "n", "o"}},
        {7, {"p", "q", "r", "s"}},
        {8, {"t", "u", "v"}},
        {9, {"w", "x", "y", "z"}}
    };
};