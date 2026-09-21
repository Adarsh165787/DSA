class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n+m;
        int mid = total/2;
        int i =0,j =0;
        int curr,prev;
        for(int k =0;k<=mid;k++){
            prev = curr;
            if(i < n && j < m){
                if(nums1[i] <= nums2[j]){
                    curr = nums1[i];
                    i++;
                }else{
                    curr = nums2[j];
                    j++;
                }
            }else if(i < n){
                curr = nums1[i];
                i++;
            }else{
                curr = nums2[j];
                j++;
            }
        }
        if(total % 2 == 1){
            return curr;
        }else{
            return (prev+curr)/2.0;
        }

    }
};