class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int i =0,j=0;
        long long ans = 0;
        while(j < n){
            if(nums[j] >= minK && nums[j] <= maxK){
                ans += j-i+1;
            }
            else{
                i = j+1;
            }
            j++;
        }
        return ans;
    }
};