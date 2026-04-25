class Solution {
public:
    long long solve(vector<int>& nums, int i, int t, vector<vector<long long>>& dp, int offset) {
        if (i == nums.size()) {
            return (t == 0) ? 1 : 0;
        }

        if (t + offset < 0 || t + offset >= dp[0].size()) return 0;

        if (dp[i][t + offset] != -1) return dp[i][t + offset];

        long long add = solve(nums, i + 1, t - nums[i], dp, offset);
        long long sub = solve(nums, i + 1, t + nums[i], dp, offset);

        return dp[i][t + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums) sum += x;

        if (abs(target) > sum) return 0;

        int offset = sum;
        vector<vector<long long>> dp(nums.size(), vector<long long>(2 * sum + 1, -1));

        return (int)solve(nums, 0, target, dp, offset);
    }
};
