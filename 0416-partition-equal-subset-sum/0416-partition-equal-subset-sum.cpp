class Solution {
public:

// bool solve(int index,vector<int>& arr,int target){
//     if(target ==0) return true;
//     if(index ==0) return (arr[0]==target);

//     bool nottake = solve(index-1,arr,target);
//     bool take = false;
//     if(target >= arr[index]){
//         take = solve(index-1,arr,target-arr[index]);
//     }
//     return take || nottake;
// }

    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum %2 ==1) return false;
        int targetsum = sum/2;
        vector<vector<int>> dp(n,vector<int>(targetsum+1,0));
        for(int i =0;i<n;i++){
            dp[i][0] = true;
        }
         if(nums[0] <= targetsum) {
        dp[0][nums[0]] = true;
    }
    for(int i =1;i<n;i++){
        for(int target =1;target <=targetsum;target++){
                bool nottake = dp[i-1][target];
                bool take = false;
                if(target >= nums[i]){
                    take = dp[i-1][target-nums[i]];
            }
            dp[i][target] = take || nottake;
        }
        
    }
        return dp[n-1][targetsum];
    }
};