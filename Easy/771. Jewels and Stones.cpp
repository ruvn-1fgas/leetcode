class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int count = 0;
        std::unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        for (char stone : stones)
        {
            if (jewelSet.count(stone))
            {
                count++;
            }
        }
        return count;
    }
};