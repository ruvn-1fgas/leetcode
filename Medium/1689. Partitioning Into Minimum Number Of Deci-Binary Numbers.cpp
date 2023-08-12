class Solution
{
public:
    int minPartitions(string n)
    {
        int max = 0;
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] - '0' > max)
            {
                max = n[i] - '0';
            }
        }
        return max;
    }
};