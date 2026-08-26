class Solution {
public:

int solve(int ind,vector<int>& num,int buy,vector<vector<int>> &dp){
    int n = num.size();
    if(ind ==n) return 0;
    long long profit =0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy){
        profit = max(-num[ind]+solve(ind+1,num,0,dp),
                      0+solve(ind+1,num,1,dp));
    }
    else{
        profit = max(num[ind]+solve(ind+1,num,1,dp),
                  0+solve(ind+1,num,0,dp));
    }
    return dp[ind][buy] = profit;
}

    int maxProfit(vector<int>& num) {
        int n = num.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,num,1,dp);
    }
};