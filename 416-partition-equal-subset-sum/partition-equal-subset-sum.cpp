class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return 0;
        int target = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++)
            dp[i][0] = 1;
        if (nums[0] <= target)
    dp[0][nums[0]] = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                bool take = false;

                if (j >= nums[i])
                    take = dp[i - 1][j - nums[i]];
                bool nt = dp[i - 1][j];
                dp[i][j] = take || nt;
            }
        }
        return dp[nums.size() - 1][target];
    }
};