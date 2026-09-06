// class Solution {
// public:
// int solve(int i ,int j ,string s, string t,vector<vector<int>> &dp){
//     if(j == t.size()){
//         return 1;
//     }
//     int pick=0,notpick=0;
//     if(i == s.size() && j != t.size()) return 0;
//     if(dp[i][j] !=  -1) return dp[i][j];
//     if(s[i] != t[j]){
//         return solve(i+1,j,s,t,dp);
//     }else{
//         pick = solve(i+1,j+1,s,t,dp);
//         notpick = solve(i+1,j,s,t,dp);
//     }
//     return dp[i][j]= pick +notpick;
// }
//     int numDistinct(string s, string t) {
//         vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
//         return solve(0,0,s,t,dp);
//     }
// };


class Solution {
public:
int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i =0;i<=n;i++){
            dp[i][m] =1;
        }
        for(int i = n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if(s[i] != t[j]){
                    dp[i][j]=dp[i+1][j];
                }else{
                    double pick = dp[i + 1][j + 1];
                    double notpick = dp[i + 1][j];
                dp[i][j]= pick +notpick;
                }
            }
        }
        return (int)dp[0][0];
    }
};