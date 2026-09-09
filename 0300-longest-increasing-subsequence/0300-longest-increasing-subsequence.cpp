class Solution {
public:
int solve(int ind,int preind,vector<int>& nums,vector<vector<int>> &dp){
    int len = 0;
    if(ind == nums.size()) return 0;
    if(dp[ind][preind+1] != -1) return dp[ind][preind+1];
    len = solve(ind+1,preind,nums,dp)+0;
    if(preind == -1 || nums[ind]>nums[preind]){
        len = max(solve(ind+1,ind,nums,dp)+1,len);
    }
    return dp[ind][preind+1] =len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};