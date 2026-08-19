class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        // here 1st column and 1st row have only one way to move.
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(i ==0 || j ==0) continue;  // at i =0 and j =0 we already calcuolate value is 1 and inislize it in dp.
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};