// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count=0;
//         for(int i =0;i<n;i++){
//             unordered_map<int,int> mpp;
//             for(int j =i;j<n;j++){
//                 mpp[nums[j]]++;
//                 if(mpp.size() ==k){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:

int solve(vector<int>& nums, int k) {
        int l=0,r=0;
        int count =0;
        unordered_map<int,int> mpp;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() >k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
            count = count+(r-l+1);
            r++;
            }
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};