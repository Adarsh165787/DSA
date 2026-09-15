class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for(auto x : nums){
            ans ^= x;   //ex:- 4^1^2^1^2 == 4 
        }
        return ans;
    }
};