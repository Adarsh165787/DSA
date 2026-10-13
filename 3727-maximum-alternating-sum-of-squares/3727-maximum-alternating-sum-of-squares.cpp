class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum =0 , sum1=0;
        vector<long long> arr;
        for(int i =0;i<n;i++){
            arr.push_back(nums[i]*nums[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i =0;i<n/2;i++){
            sum += arr[i];
        }
        for(int i =n/2;i<n;i++){
            sum1 += arr[i];
        }
        return sum1 - sum;
    }
};