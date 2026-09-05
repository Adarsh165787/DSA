class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tsum =0,sum =0;
        for (int i =0;i<n;i++) tsum += nums[i];
        int target = tsum-x;
        if(target <0) return -1;
        int l =0,r=0,maxlen=0;
        while(r <n){
            sum += nums[r];
            while(sum > target){
                sum = sum-nums[l];
                l++;
            }
            if(sum == target) {
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        if(maxlen == 0 && target != 0) {
            return -1;
        }
        return n-maxlen;
    }
};