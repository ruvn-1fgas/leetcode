class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> indices(n, 0);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        result.push_back(nums);
        while (true) {
            int i = n - 2;
            while (i >= 0 && indices[i] >= indices[i + 1]) {
                i--;
            }
            if (i < 0) {
                break;
            }
            int j = n - 1;
            while (indices[j] <= indices[i]) {
                j--;
            }
            swap(indices[i], indices[j]);
            reverse(indices.begin() + i + 1, indices.end());
            vector<int> permutation(n);
            for (int k = 0; k < n; k++) {
                permutation[k] = nums[indices[k]];
            }
            result.push_back(permutation);
        }
        return result;
    }
};