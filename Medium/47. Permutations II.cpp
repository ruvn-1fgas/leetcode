class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        while (true)
        {
            int i = nums.size() - 2;
            while (i >= 0 && nums[i] >= nums[i + 1])
            {
                i--;
            }
            if (i < 0)
            {
                break;
            }
            int j = nums.size() - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            result.push_back(nums);
        }
        return result;
    }
};