class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixgcd;
        int mx =0;
        for(int i =0;i<n;i++){
            mx = max(nums[i],mx);
            prefixgcd.push_back(gcd(nums[i],mx));
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long  sum =0;
        int i =0;
        int j = n-1;
        while(i < j){
            sum += gcd(prefixgcd[i], prefixgcd[j]);
            i++;
            j--;
            
        }
        return sum;
    }
};