class Solution {
public:
    int findLength(vector<int>& num, vector<int>& nums) {
       int n = num.size();
       int m = nums.size();
       vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       int ans =0;
       for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(num[i-1]==nums[j-1]){
                dp[i][j] =1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
       }
       return ans;
    }
};