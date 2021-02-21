int dp[1001][1001] = {};
int dfs(vector<int> &nums, vector<int> &mul, int l, int i) {
    if (i >= mul.size()) 
        return 0;
    if (!dp[l][i]) {
        int r = nums.size() - 1 - (i - l);            
        dp[l][i] = max( nums[l] * mul[i] + dfs(nums, mul, l + 1, i + 1), 
        nums[r] * mul[i] + dfs(nums, mul, l, i + 1));
    }
    return dp[l][i];
}
int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    return dfs(nums, multipliers, 0, 0);
}