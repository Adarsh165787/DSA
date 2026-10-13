class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum =0 , sum1=0;
        for(int i =0;i<n;i++){
            nums[i] = nums[i]*nums[i];
        }
        // sort(arr.begin(),arr.end());
        nth_element(begin(nums),begin(nums)+n/2,end(nums));
        for(int i =0;i<n/2;i++){
            sum += nums[i];
        }
        for(int i =n/2;i<n;i++){
            sum1 += nums[i];
        }
        return sum1 - sum;
    }
};