class Solution {
public:

int solve(int ind,vector<int> &num,int buy,int fee,vector<vector<int>> &dp){
    int n = num.size();
    if(ind ==n) return 0;
    int profit =0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy){
        profit  = max(-num[ind]+solve(ind+1,num,0,fee,dp),
                       0+solve(ind+1,num,1,fee,dp));
    }
    else{
        profit = max(num[ind]-fee+solve(ind+1,num,1,fee,dp),
                    0+solve(ind+1,num,0,fee,dp));
    }
    return dp[ind][buy] = profit;
}

    int maxProfit(vector<int>& num, int fee) {
        int n = num.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,num,1,fee,dp);
    }
};