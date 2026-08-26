// class Solution {
// public:
// int solve(int ind,vector<int>& num,int buy,vector<vector<vector<int>>>  &dp,int cap){
//     int n = num.size();
//     if(ind ==n) return 0;
//     if(cap ==0) return 0;
//     long long profit =0;
//     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
//     if(buy){
//         profit = max(-num[ind]+solve(ind+1,num,0,dp,cap),
//                       0+solve(ind+1,num,1,dp,cap));
//     }
//     else{
//         profit = max(num[ind]+solve(ind+1,num,1,dp,cap-1),
//                   0+solve(ind+1,num,0,dp,cap));
//     }
//     return dp[ind][buy][cap] = profit;
// }

//     int maxProfit(vector<int>& num) {
//         int n = num.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//         return solve(0,num,1,dp,2);
//     }
// };







class Solution {
public:
    int maxProfit(vector<int>& num) {
        int n = num.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        dp[n][0][0]=dp[n][1][0] =0;
        for(int ind = n-1;ind>= 0;ind--){
            for(int buy =0;buy <=1;buy++){
                for (int cap = 1; cap <= 2; cap++) {
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
        return dp[0][1][2];
    }
};