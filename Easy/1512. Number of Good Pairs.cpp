class Solution
{
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int count = 0;
        std::unordered_map<int, int> freq;
        for (int num : nums)
        {
            count += freq[num]++;
        }
        return count;
    }
};