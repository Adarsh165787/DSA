class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi =0,ans =INT_MAX;
        vector<int> sufixmini(n);
        sufixmini[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            sufixmini[i]= min (nums[i],sufixmini[i+1]);
        }
        for(int i =0;i<n;i++){
            maxi = max(maxi,nums[i]);
            int mini = sufixmini[i];
            ans = maxi-mini;
            if(ans <=k){
                return i;
            }
        }
        return -1;
    }
};