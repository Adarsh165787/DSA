class Solution {
public:
    int maxProfit(int k, vector<int>& num) {
        int n = num.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        dp[n][0][0]=dp[n][1][0] =0;
        for(int ind = n-1;ind>= 0;ind--){
            for(int buy =0;buy <=1;buy++){
                for (int cap = 1; cap <= k; cap++) {
                    long long profit =0;
                if(buy){
                    profit = max(-num[ind]+dp[ind+1][0][cap],
                                0+dp[ind+1][1][cap]);
                }
                else{
                    profit = max(num[ind]+dp[ind+1][1][cap-1],
                            0+dp[ind+1][0][cap]);
                }
                dp[ind][buy][cap]=profit;
            }
        }
    }
        return dp[0][1][k];
    }
};