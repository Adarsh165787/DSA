class Solution {
public:
    int change(int target, vector<int>& num) {
        int n = num.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(target + 1, 0));

        for(int i =0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int t = 1; t <= target; t++) {
            if(t % num[0] == 0) {
                dp[0][t] = 1;
            }
        }
        for(int i =1;i<n;i++){
            for(int t = 0;t <= target;t++){
                unsigned long long nottake = dp[i - 1][t];
                unsigned long long take = 0;
                if(num[i] <= t) {
                    take = dp[i][t - num[i]];
                }
            dp[i][t] = (take + nottake);
        }
    }
    return dp[n - 1][target];
    }
};