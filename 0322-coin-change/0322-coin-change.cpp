// class Solution {
// public:

// int solve(int ind,vector<int>& num, int target,vector<vector<int>> &dp){
//     if(ind ==0){
//         if(target%num[ind] ==0) return target/num[0];
//         else return 1e9;
//     }
//     if(dp[ind][target] != -1) return dp[ind][target];
//     int nottake = 0+ solve(ind-1,num,target,dp);
//     int take = INT_MAX;
//     if(target >= num[ind]){
//         take = 1+ solve(ind,num,target-num[ind],dp);
//     }
//     return dp[ind][target] =min(take,nottake);
// }

//     int coinChange(vector<int>& num, int target) {
//         int n = num.size();
//         vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//         int ans = solve(n-1,num,target,dp);
//         if(ans >= 1e9) return -1;
//         return ans;
//     }
// };


class Solution {
public:
 int coinChange(vector<int>& num, int target) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for(int t =0;t<= target;t++){
        if(t %num[0] ==0){
            dp[0][t] = t/num[0];
        }else{
            dp[0][t] = 1e9;
        }
    }
for(int ind =1;ind<n;ind++){
    for(int t =0;t<=target;t++){
        int nottake = 0+ dp[ind-1][t]; 
        int take = INT_MAX;
        if(t>= num[ind]){
        take = 1+ dp[ind][t-num[ind]];
        }
        dp[ind][t]=min(take,nottake);
    }
}
    int ans = dp[n - 1][target];
    if(ans >= 1e9)
        return -1;
    return ans;
    }
};